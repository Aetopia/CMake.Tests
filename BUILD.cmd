@echo off
set CMAKE_SUPPRESS_DEVELOPER_WARNINGS=ON
set CMAKE_POLICY_VERSION_MINIMUM=3.5

cd "%~dp0"
rd /q /s "src/bin"

cmake.exe -S "." -B "src/obj" --fresh
cmake.exe --build "src/obj" --clean-first