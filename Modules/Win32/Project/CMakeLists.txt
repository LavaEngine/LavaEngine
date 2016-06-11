project(${current_module})

#Defs
add_definitions(-DUNICODE -D_UNICODE)

#Paths
get_filename_component(source_path "../Source" ABSOLUTE)
get_filename_component(public_path "../Public" ABSOLUTE)

#Extensions
set(source_ext c cpp)
set(header_ext h hpp)

foreach(ext ${source_ext} ${header_ext})
	set(source_search_exp ${source_search_exp} "${source_path}/*.${ext}")
	set(public_search_exp ${public_search_exp} "${public_path}/*.${ext}")
endforeach()

#Source files
file(GLOB_RECURSE source_files ${source_search_exp})
file(GLOB_RECURSE public_files ${public_search_exp})

source_group("Source" FILES ${source_files})
source_group("Public" FILES ${public_files})

#Binaries
add_executable(${current_module} ${source_files} ${public_files})
target_link_libraries(${current_module}
	${link_library_files}
	Renderer
)

set(CMAKE_BINARY_DIR ${binaries_path})
set_target_properties(${current_module} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
