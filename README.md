# About

The ft_printf function prints formatted output to the standard output. It is a recreation of the famous C library printf function. 

## Parameters
str – The input null-terminated string containing the format specifier.
… – Optional arguments to be formatted based on the format specifier.

## Return
The total number of characters written to the standard output.

## Description
The ft_printf function prints formatted output to the standard output according to the format specifier in the input string str. It supports several format specifiers.

## Format Specifiers
**%c:** Print a single character.
**%s:** Print a null-terminated string.
**%d:** or %i: Print a signed integer.
**%X:** or %x: Print an unsigned integer in hexadecimal format.
**%p:** Print the address of a pointer in hexadecimal format.
**%u:** Print an unsigned integer in decimal format.
**%%:** Print a percent sign '%'.
