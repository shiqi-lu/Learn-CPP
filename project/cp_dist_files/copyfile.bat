@echo off
set "file=%1"
set "dir=%2"

if not exist %file% goto end

if not exist %dir%  mkdir %dir%

for /f "tokens=*" %%a in ('type %file%') do (
    @copy %%a %dir% >NUL
)

:end
echo SUCCESS
