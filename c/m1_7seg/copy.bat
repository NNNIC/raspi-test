cd /d %~dp0
robocopy . \\192.168.1.6\share\7seg *.c *.sh
::pause 
exit