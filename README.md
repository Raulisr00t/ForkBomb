# Windows Fork Bomb

## Description
This is a simple Windows fork bomb written in C. It continuously creates new processes in an infinite loop using `CreateProcess()`, leading to system resource exhaustion.

## How It Works
- The program spawns 10 threads.
- Each thread continuously spawns new processes of itself.
- This rapidly escalates, consuming CPU and memory, potentially crashing the system.

## Warning
⚠️ **Do not run this on a critical system!**  
This program is for educational purposes only and can cause serious disruption.

## Compilation
Use MinGW or MSVC to compile:
```powershell
gcc forkbomb.c -o forkbomb.exe
```

## Disclaimer
This software is provided for educational and research purposes only. Use at your own risk.
