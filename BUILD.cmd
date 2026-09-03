@echo off
cd "%~dp0"

cmake.exe -S "." -B "src/obj" --fresh
cmake.exe --build "src/obj"