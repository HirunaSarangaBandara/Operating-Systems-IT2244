@echo off
echo Age Calculator
echo --------------

set /p birthYear=Enter your birth year :
:: set is used for creates or modifies a variable
:: p is used for get the user input. 

set /a currentYear=%date:~-4%
:: a is used for enable arithmetic operations.
:: %date:~-4% is used to extract the last 4 digits of %date% command.

set /a age=%currentYear% - %birthYear%

echo Your age : %age% years old.
:: Display the age calculated based on the user input.

pause