### The *short, int, long* and *long long* Integer Types

By using different numbers of bits to store values, the C++ types *short, int, long* can
represent up to four different integer widths. No one is suitable for all computer designs.
C++ offers a flexible standard with some guaranteed minimum sizes:
- A `short` integer is at least *16* bits wide.
- An `int` integer is at least as big as `short`.
- A `long` integer is at least *32* bits wide and at least as big as `int`.
- A `long long` integer is at least *64* bits wide and at least as big as `long`.

- Example ([limits.cpp](../programs/chapter-3/limits/limits.cpp))

If you want to know how your system's integers size up, you can use the C++ tools:
- `sizeof` returns the size, in bytes, of a type or a variable.
- `climits` header file contains information about integer type limits. In particular
it defines symbolic names to represent different limits.

The program also illustrates *initialization*, which is the use of a declaration statement to assign a value to a variable.

### Unsigned Types

Each one of the four integer types comes in an unsigned variety that can't hold negative values. This has the
advantage of increasing the largest value the variable can hold.

To create unsigned versions of the basic integer types, you just use the keyword `unsigned` to modify the declarations:

```cpp
unsigned short change;
unsigned int rovert;
unsigned quarterback;
unsigned long gone;
unsigned long long lang_lang;
```

Note that `unsigned` by itself is short for `unsigned int`.

The example [exceed.cpp](../programs/chapter-3/exceed/exceed.cpp) shows what might happen if your program tries to go beyond the limits for integer types.

Fixed-size integer types have a limited range. When a value goes past that range, it
doesn't error out — it **wraps around** to the other end, like a car odometer rolling
over from 999999 back to 000000.

- **Signed types** (e.g. `short`, range -32,768 to 32,767): going past the max wraps
  around to the *minimum*. `32767 + 1` becomes `-32768`.
- **Unsigned types** (e.g. `unsigned short`, range 0 to 65,535): going below 0 wraps
  around to the *maximum*. `0 - 1` becomes `65535`.

C++ **guarantees** this wraparound behavior for unsigned types, but does **not**
guarantee it for signed types (overflow on signed types is technically undefined
behavior — wraparound is just the common behavior on most current systems).

### Choosing an Integer Type

*Natural Size* refers to the integer form that the compiler handles more efficiently. If there's no compelling reason to choose another type, you should use `int`.

If a variable represents something that is never negative, you can use an unsigned type; that way the variable can represent higher values.

If you know that the variable might have to represent integer values greater than a 16-bit integer, you should use `long`. And if a mere two billion is inadequate
for your needs, you can move up to `long long`.

Using `short` can conserve memory if `short` is smaller than `int`. Most typically, this is important only if you have a large array of *integers*.
If conserving space is important, you should use `short` instead of `int`, even if the two are the same size.
If you need only a single byte, you can use `char`.