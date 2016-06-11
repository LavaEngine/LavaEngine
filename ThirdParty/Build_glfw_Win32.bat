@echo off
set last_working_dir=%cd%
cd /d %~dp0

set library_dir=%~dp0/glfw
set install_dir=%library_dir%/prebuilt/win32

echo Build win32...
cd %library_dir%
mkdir build
cd build

cmake -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=%install_dir% -G "Visual Studio 14" ..
cmake --build . --config Release --target INSTALL

echo Build win64...
cd %library_dir%
mkdir build64
cd build64

cmake -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=%install_dir% -DLIB_SUFFIX=64 -G "Visual Studio 14 Win64" ..
cmake --build . --config Release --target INSTALL

cd %last_working_dir%
