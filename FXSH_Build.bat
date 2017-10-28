@echo off
rem Do not edit! This batch file is created by CASIO fx-9860G SDK.

if exist debug\*.obj  del debug\*.obj
if exist ALCHEMY.G1A  del ALCHEMY.G1A

cd debug
if exist FXADDINror.bin  del FXADDINror.bin
"B:\Program Files\Casio\fx-9860G SDK\OS\SH\Bin\Hmake.exe" Addin.mak
cd ..
if not exist debug\FXADDINror.bin  goto error

"B:\Program Files\Casio\fx-9860G SDK\Tools\MakeAddinHeader363.exe" "B:\Users\Pedro\Documents\Casio Calculators\Projects\Alchemy"
if not exist ALCHEMY.G1A  goto error
echo Build has completed.
goto end

:error
echo Build was not successful.

:end

