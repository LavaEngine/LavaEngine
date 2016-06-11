@echo off
set last_working_dir=%cd%
cd /d %~dp0

set library_dir=%~dp0/vkcpp
set install_dir=%library_dir%/prebuilt/win32

echo Build win32...
cd %library_dir%
mkdir build
cd build

cmake -DCMAKE_INSTALL_PREFIX=%install_dir% -G "Visual Studio 14" ..
cmake --build . --config Release

Release\VkCppGenerator.exe

cd %last_working_dir%
