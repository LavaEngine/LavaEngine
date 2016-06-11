project(LavaEngine)
cmake_minimum_required(VERSION 3.0)

#Options
option(conan_enabled "Enable Conan Dependency Manager?" OFF)
set(link_library_files )

#Paths
get_filename_component(thirdparty_path "../ThirdParty" ABSOLUTE)
get_filename_component(modules_path "../Modules" ABSOLUTE)
get_filename_component(binaries_path "../Binaries" ABSOLUTE)

#Conan Dependency Manager
if(conan_enabled)
	include(conanbuildinfo.cmake)
	conan_basic_setup()
endif()

if(MSVC)
	SET(LIBRARY_PREFIXES "")
	SET(LIBRARY_SUFFIXES ".lib")
elseif(GNU)
	SET(LIBRARY_PREFIXES "lib")
	SET(LIBRARY_SUFFIXES ".a")
endif()

#ThirdParty
file(GLOB thirdparty_files "${thirdparty_path}/ThirdParty_*.txt")
foreach(file ${thirdparty_files})
	if(EXISTS ${file})
		file(RELATIVE_PATH thirdparty ${thirdparty_path} ${file})
		string(LENGTH ${thirdparty} len)
		math(EXPR len "${len}-11-4")
		string(SUBSTRING ${thirdparty} 11 ${len} thirdparty)

		message(STATUS "Found thirdparty: ${thirdparty}")
		
		set(current_thirdparty ${thirdparty})
		include(${file})
	endif()
endforeach()

#Modules
file(GLOB module_dirs "${modules_path}/*")
foreach(dir ${module_dirs})
	if(IS_DIRECTORY ${dir})
		file(RELATIVE_PATH module ${modules_path} ${dir})
		message(STATUS "Found module: ${module}")
		
		set(current_module ${module})
		add_subdirectory("${dir}/Project" "SubModules/${module}")
	endif()
endforeach()
