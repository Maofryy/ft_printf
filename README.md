## ft_printf
Recoding the printf function, respecting multiples behaviors of this beautiful work

# FLAGS

This is a list of the minimum behaviors to respect

| Option | Behavior |
| ------:| --------:|
| hh | convert integer into signed char or unsigned char |
| h | convert integer into signed short int or unsigned short int |
| l | convert integer into signed long int or unsigned long int |
| ll | convert integer into signed long long int or unsigned long long int |
| L | convert integer into a long double (signed or unsigned ?) |
|||
| "#" | Adds a prefixe to the following argument |
||      o : adds 0 before the conversion |
||      x,X : adds 0x,0X before the conversion |
| "0" | Padds with zeros |
||      Used with numeric conversions, the value is padded with 0 on the left instead of blanks
||      If used with the - flag, has no effect
||      Used with precision on non decimal conversions, this flag has no effect
| "-" | Add spaces |
||      After the initial conversions, displays spaces corresponding of the following value
| " " | Changing display of positive numeric values |
||      Add a space before a positive number, where it could be a "-" if the number where negative |
| "+" | Also changed the display of positive numeric values |
||      Add a + before a positive number, same as the " " flag |
||      Overrules the " " flag when used simultaneously |
| "[int]" | Field Width |
||      Specify a minimum field width
||      Adds spaces if the converted value has less characters than the passed value |
<!-- ||      Can be passed as argument using | -->
||      Doesnt not cause truncation if the value is smaller than the converted value characters |
| ".[int]" | Precison |
||      Coupled with a non decimal conversion, gives the minimum of digits to appear |
||      Coupled with a decimal conversion, gives the minimum of digits to appear after the radix |
||      Coupled with a string conversion, gives the maximum of characters to appear |


Extra behaviors :

| Option | Behavior |
| ------:| --------:|

# FORMATS

This is a list of the handled formats of this functions

| Option | Behavior |
| ------ | -------- |
| "c" | Char |
| "s" | String |
| "p" | void* / prints in hexa the value of the pointer |
| "d" or "i" | int |
| "o" | unsigned int in octal base |
| "u" | unsigned int in decimal base |
| "x" or "X" | unsigned int in hexadecimal base, using mins and Majs respectivly |
| "f" | double as a float, displays 6 digits by default precision |

Extra behaviors :

| Option | Behavior |
| ------:| --------:|
 
