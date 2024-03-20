@REM {fileName} 변수를 받아 fileName.cpp파일을 g++로 빌드해서 sol.exe를 생성한다.

@echo off
set fileName=%1
g++ -o sol.exe %fileName%.cpp

@REM print '>> build success'
@echo ^>^> build success