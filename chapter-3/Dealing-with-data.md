### The *short, int, long* and *long long* integer Types

By using diferent numbers of bits to store values, the C++ types *short, int, long* can
represent up to four different integer widths. No one is suitable for all computers designs.
C++ offers a flexible standard with some guaranteed minimum sizes:
- A `short` integer at least *16* bits wide.
- An `int` integer is at least as big as `short`. 
- A `long` integer is at least *32* bits wide and at least as big as `int`.
- A `long long` integer is at least *64* bits wide and at least as big as `long`.

- Example ([limits.cpp](../programs/chapter-3/limits/limits.cpp))


If you want to know how your system's integer size up, you can use the C++ tools
- `sizeof`return the the size, in bytes, of a type or a variable.
- `climits` header file contains information about integer type limits. In particular 
it defines symbolic names o represent different limits.

The program also illustrates *inititalization*, which is the use of a declaration statement to assign a value to a variable.


### Unsigned Types

Each one of the four integers types comes in an unsigned variety that can't hold negative values. This has the advantage of increasing
the largest value the variable can hold.

To create unsigned versions of the basic integer types, you just use the keyword `unsigned` to modify the declarations:

```cpp
unsigned short change;
unsigned int rovert;
unsigned quarterback;
unsigned long gone;
unsigned long long lang_lang;
```
Note that unsigned by itself is short for unsigned

