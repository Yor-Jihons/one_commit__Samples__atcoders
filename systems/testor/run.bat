@echo off

set TESTOR=.\bin\testor.exe
echo SETTING .
set TARGET=A__Many_A_Plus_B_Problems
echo SETTING ..
echo SETTING ...
set TEST_MAIN=.\bin\test_main.exe

%TESTOR% .\test\%TARGET% .\test\%TARGET%__input1.txt .\test\%TARGET%__output1.txt
%TEST_MAIN%
