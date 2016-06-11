@echo off
set last_working_dir=%cd%
cd /d %~dp0

if not exist "freeimage" (
	tools\win32\axel http://downloads.sourceforge.net/freeimage/FreeImage3170.zip
	tools\win32\axel http://downloads.sourceforge.net/freeimage/FreeImage3170Win32Win64.zip

	tools\win32\unzip -o FreeImage3170.zip
	tools\win32\unzip -o FreeImage3170Win32Win64.zip
)

if not exist "freeimage" (
	echo Failed to download the library.
	goto END
)

:END
cd %last_working_dir%
