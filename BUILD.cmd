@echo off

cd "%~dp0"
rd /q /s "src/bin"

cmake.exe -S "." -B "src/obj" --fresh
cmake.exe --build "src/obj" --clean-first