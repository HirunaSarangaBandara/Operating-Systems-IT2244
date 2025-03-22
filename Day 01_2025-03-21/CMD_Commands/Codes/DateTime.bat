@echo off
echo Display Date and Time
echo ---------------------

echo Full Date : %date%
:: %date% command is used for displays the complete system date in the default format.

echo Day : %date:~7,2%
:: %date:~7,2% is used for extract 2 digits from date starting from 7th digit.

echo Day of the week : %date:~0,3%
:: %date:~0,3% is used for extract 3 digits from date starting from 0th digit.

echo Month : %date:~4,2%
:: %date:~4,2% is used for extract 2 digits from date starting from 4th digit.

echo Year : %date:~-4%
:: %date:~-4% is used for extract last 4 digits from date.

pause