@echo off
cls
setlocal

REM default parameter value
set QTVERSION=5.14.2
set XPCFROOT=../..

REM check whether user had supplied -h or --help . If yes display usage 
for %%A in ("--help" "-h") do if "%1"==%%A (call:display_usage %1 & exit /b 0)

REM default win walues
if NOT [%1]==[] set XPCFROOT=%1
if NOT [%2]==[] set QTVERSION=%2


if not exist %XPCFROOT% (echo "XPCF project root path '%XPCFROOT%' doesn't exist" & exit /b 2)
echo "XPCF project root path used is : %XPCFROOT%"

call %XPCFROOT%/scripts/win/build_xpcf_shared.bat %XPCFROOT% %QTVERSION%
call %XPCFROOT%/scripts/win/build_testxpcf.bat %XPCFROOT% %QTVERSION%
call %XPCFROOT%/scripts/win/build_xpcf_static.bat %XPCFROOT% %QTVERSION%

endlocal
goto:eof


::--------------------------------------------------------
::-- Function display_usage starts below here
::--------------------------------------------------------

:display_usage

echo This script builds %PROJECT% in shared mode.
echo It can receive two optional argument. 
echo.
echo Usage: param [path to xpcf project root - default='%XPCFROOT%'] [Qt kit version to use - default='%QTVERSION%']
exit /b 0

:end






