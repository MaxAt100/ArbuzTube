@ECHO OFF
PUSHD "%~dp0"
set _arch=x86
IF "%PROCESSOR_ARCHITECTURE%"=="AMD64" (set _arch=x86_64)
IF DEFINED PROCESSOR_ARCHITEW6432 (set _arch=x86_64)
PUSHD "%_arch%"

start "" goodbyedpi.exe -6 -e1 -q --fake-gen 29 --fake-from-hex b6a243262259a8eb26f14a1f28f56af9240b7ae2ecd822ca1db0ebff237fc40eb1bf112563c97ddd2607125e306485060a3a9553b4af58cedd70
--blacklist ..\russia-blacklist.txt --blacklist ..\russia-youtube.txt

POPD
POPD