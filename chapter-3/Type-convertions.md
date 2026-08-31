## Conversion on Initialization and Assignment

C++ is fairly liberal in allowing you to assign a numeric value of one type to a variable of
another type — the value is converted to the type of the receiving variable.

```cpp
so_long = thirty;   // assigning a short to a long
```

The program takes the value of `thirty` (typically a 16-bit value) and expands it to a `long`
value (typically 32-bit) upon making the assignment. The expansion creates a **new** value to
place into `so_long`; the contents of `thirty` are unaltered.

Assigning a value to a type with a greater range usually poses no problem (e.g. `short` → `long`
just gives the value more bytes to sit in). But assigning a large `long` value to a `float` can
lose precision — a `float` only holds about six significant figures, so `2111222333` would round
to `2.11122E9`.

### Potential Numeric Conversion Problems

| Conversion Type | Potential Problems |
|---|---|
| Bigger floating-point type to smaller floating-point type, such as `double` to `float` | Loss of precision (significant figures); value might be out of range for target type, in which case result is undefined. |
| Floating-point type to integer type | Loss of fractional part; original value might be out of range for target type, in which case result is undefined. |
| Bigger integer type to smaller integer type, such as `long` to `short` | Original value might be out of range for target type; typically just the low-order bytes are copied. |

A zero value assigned to a `bool` variable is converted to `false`, and a nonzero value is
converted to `true`.

Assigning floating-point values to integer types poses a couple of problems:
1. Converting floating-point to integer **truncates** the number (discards the fractional part).
2. A `float` value might be too big to fit in a cramped `int` variable.