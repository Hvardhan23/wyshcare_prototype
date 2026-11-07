$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $projectRoot

if (-not (Get-Command python -ErrorAction SilentlyContinue)) {
    throw 'Python was not found. Install Python and ensure it is available on PATH.'
}

python -m pip install -r requirements.txt
if ($LASTEXITCODE -ne 0) {
    throw 'Failed to install Python requirements.'
}

python -m platformio run
if ($LASTEXITCODE -ne 0) {
    throw 'PlatformIO build failed.'
}
