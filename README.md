# ql
Quiet Launcher for console applications

This is an extremely simple, yet super useful utility. It just calls `CreateProcess` with `CREATE_NO_WINDOW` flag. Thus, if you pass it some console application or `.cmd` script, it will be launched silently in a background, without creating any console windows. Even more useful is the fact that the utility itself is compiled as `SUBSYSTEM:WINDOWS`, so it will never spawn any console window of its own, for fully silent operation!

Use it like this:
```
ql "cmd /q /c C:\scripts\your_script.cmd"
```
Or you can just call any stand-alone console program:
```
ql your_console_program.exe
```
