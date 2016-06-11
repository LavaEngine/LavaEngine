@echo off
set last_working_dir=%cd%
cd /d %~dp0

git clean -f -x -d

cd %last_working_dir%
