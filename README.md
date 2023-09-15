0x11. C - printf

Inside this project the following functions are resolved:

* A function that produces output according to a format
* A function that handles conversion specifiers:
            ->d
            ->i
* A function that handles conversion specifiers:
            ->b: the unsigned int argument is converted to binary

* A function that handles conversion specifiers:
            ->u
            ->o
            ->x
            ->X

* A function that uses local buffer of 1024 chars in order to call write as little as possible

* A function that handles conversion specifiers:
            -> S : prints the string.
            -> Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

* A function that handles conversion specifiers: p.
* A function that Handles the following flag characters for non-custom conversion specifiers:
              ->+
              ->space
              ->#
* A function that handles the following length modifiers for non-custom conversion specifiers:
              ->l
              ->h
Conversion specifiers to handle: d, i, u, o, x, X

* A function that handles  the field width for non-custom conversion specifiers
* A  function that handles precision for non-custom conversion specifiers
* A function that handles the 0 flag character for non-custom conversion specifiers
* A function that handles the - flag character for non-custom conversion specifiers
* A function that handles the following custom conversion specifier: 
               -> r : prints the reversed string

* A function that handles the following custom conversion specifier:
               -> R: prints the rot13'ed string

* A final check that All the above options work well together   
