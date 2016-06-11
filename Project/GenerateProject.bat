@echo off
set last_working_dir=%cd%
cd /d %~dp0

mkdir VisualStudio
cd VisualStudio

conan install ..
cmake -G "Visual Studio 14 Win64" ..

cd %last_working_dir%
