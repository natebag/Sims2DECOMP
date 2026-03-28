@echo off
cd /d "%~dp0"
echo Running SDK/runtime extraction...
echo.

REM Try Python 3.13 first, then 3.12
set PYTHON=
if exist "C:\Users\SCICO\AppData\Local\Programs\Python\Python313\python.exe" (
    set PYTHON=C:\Users\SCICO\AppData\Local\Programs\Python\Python313\python.exe
) else if exist "C:\Users\SCICO\AppData\Local\Programs\Python\Python312\python.exe" (
    set PYTHON=C:\Users\SCICO\AppData\Local\Programs\Python\Python312\python.exe
) else (
    where python >nul 2>nul
    if %errorlevel% equ 0 (
        set PYTHON=python
    ) else (
        echo ERROR: Python not found!
        pause
        exit /b 1
    )
)

echo Using Python: %PYTHON%
"%PYTHON%" extract_and_assemble.py
echo.
echo Return code: %errorlevel%
pause
