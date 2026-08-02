@echo off
REM Compile predict_the_winner.c into predict_the_winner.exe, run it, then push changes
gcc predict_the_winner.c -o  .\predict_the_winner.exe
predict_the_winner.exe

