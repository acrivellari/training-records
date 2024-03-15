@echo off

echo * Run CMake to create the configuration build files 
echo:

set source="."
set build="build1"
set generator="MinGW Makefiles"
cmake -S %source% -B %build% -G %generator%

echo:
echo * Build the project, through makefile, and obtain the executable
echo:

cd %build%
mingw32-make
set /p id=Press a key...