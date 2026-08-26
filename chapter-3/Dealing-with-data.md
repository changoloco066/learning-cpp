### The *short, int, long* and *long long* integer Types

By using diferent numbers of bits to store values, the C++ types *short, int, long* can
represent up to four different integer widths. No one is suitable for all computers designs.
C++ offers a flexible standard with some guaranteed minimum sizes:
- A `short` integer at least *16* bits wide.
- An `int` integer is at least as big as `short`. 
- A `long` integer is at least *32* bits wide and at least as big as `int`.
- A `long long` integer is at least *64* bits wide and at least as big as `long`.

[Ex limits.cpp](../programs/chapter-3/limits.cpp)
If you want to know how your system's integer size up, you can use the C++ tools
`sizeof`return the 