# Chapter 3: Type Conversions

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

### Conversions During Initialization

Traditional initialization behaves the same as assignment — the value is converted to the type
of the variable being initialized.

Example: [init.cpp](../programs/chapter-3/init/init.cpp)

Output on one system:
```
tree = 3.000000
guess = 3
debt = 1634811904
```

- `tree` is initialized to `3` (an `int`), which gets converted to the floating-point value `3.0`.
- `guess` is initialized to `3.9832` (a `double`), which gets **truncated** to `3` — C++ truncates
  (discards the fractional part) rather than rounding when converting floating-point types to
  integer types.
- `debt` is initialized to `7.2E12`, a value way too big for an `int` to hold. This is a case
  where **C++ doesn't define what the result should be** — different implementations (compilers/
  systems) can respond differently. On this system it produced `1634811904`; on another system,
  the same program produced `2147483647` instead.

Some compilers warn about possible data loss when initializing integer variables with
floating-point values.

### Conversions in Expressions

When C++ evaluates an expression with two different arithmetic types, it applies automatic conversions so both operands end up as the same type before the operation happens.

**Integral promotion:** first, `bool`, `char`, `unsigned char`, `signed char`, and `short` values are converted to `int` (with `true` promoted to 1 and `false` to 0).

The compiler goes through the following checklist **in order**, stopping at the first one that applies:

1. If either operand is `long double`, the other operand is converted to `long double`.
2. Otherwise, if either operand is `double`, the other operand is converted to `double`.
3. Otherwise, if either operand is `float`, the other operand is converted to `float`.
4. Otherwise, the operands are integer types and the integral promotions are made (see above).
5. In that case, if both operands are signed or both are unsigned, and one is of lower rank than the other, it is converted to the higher rank.
6. Otherwise, one operand is signed and one is unsigned. If the unsigned operand is of higher rank than the signed operand, the latter is converted to the type of the unsigned operand.
7. Otherwise, if the signed type can represent all values of the unsigned type, the unsigned operand is converted to the type of the signed type.
8. Otherwise, both operands are converted to the unsigned version of the signed type.

**Integer type ranking**, from highest to lowest:

`long long` > `long` > `int` > `short` > `signed char`

- Unsigned types have the same rank as their corresponding signed type.
- `char`, `signed char`, and `unsigned char` all have the same rank.
- `bool` has the lowest rank.
- `wchar_t`, `char16_t`, and `char32_t` have the same rank as their underlying types.

> K&R (classic) C always promoted `float` to `double`, even if both operands were `float`; C++11 no longer does this (see point 3).

## Type Casts

C++ empowers you to force type conversions explicitly via the type cast mechanism. (C++ recognizes the need for type rules, and it also recognizes the need to occasionally override those rules.) The type cast comes in two forms. For example, to convert an `int` value stored in a variable called `thorn` to type `long`, you can use either of the following expressions:

```cpp
(long) thorn    // old C syntax
long (thorn)    // new C++ syntax
```

The type cast doesn't alter the `thorn` variable itself; instead, it creates a new value of
the indicated type, which you can then use in an expression, as in the following:

```cpp
cout << int('Q');  // displays the integer code for 'Q'
```

More generally, you can do the following:

```cpp
(typeName) value   // converts value to typeName type
typeName (value)   // converts value to typeName type
```

The first form is straight C. The second form is pure C++. The idea behind the new
form is to make a type cast look like a function call. This makes type casts for the built-in
types look like the type conversions you can design for user-defined classes.

C++ also introduces four type cast operators that are more restrictive in how they can
be used. Of the four, the `static_cast<>` operator can be used for converting values from one numeric type to
another. For example, using it to convert `thorn` to a type `long` value looks like this:

```cpp
static_cast<long> (thorn)   // returns a type long conversion of thorn
```

More generally, you can do the following:

```cpp
static_cast<typeName> (value)   // converts value to typeName type
```

Stroustrup felt that the traditional C-style type cast is dangerously unlimited in its possibilities. The `static_cast<>` operator is more restrictive than the traditional type cast.

### Example — `typecast.cpp`

```cpp
// typecast.cpp -- forcing type changes
#include <iostream>
int main()
{
    using namespace std;
    int auks, bats, coots;

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;

    // these statements add values as int
    bats = (int) 19.99 + (int) 11.99;   // old C syntax
    coots = int (19.99) + int (11.99);  // new C++ syntax
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";
    cout << int(ch) << endl;              // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl; // using static_cast
    return 0;
}
```

Output:
```
auks = 31, bats = 30, coots = 30
The code for Z is 90
Yes, the code is 90
```

First, adding `19.99` to `11.99` yields `31.98`. When this value is assigned to the `int` variable `auks`, it's truncated to `31`. But using type casts truncates the same two values to `19` and `11` before addition, making `30` the result for both `bats` and `coots`. Then two `cout` statements use type casts to convert a type `char` value to `int` before they display the result. These conversions cause `cout` to print the value as an integer rather than as a character.

This program illustrates two reasons to use type casting:

1. You might have values that are stored as type `double` but are used to calculate a type `int` value — for example, values that might be fitting a position to a grid or modeling integer values, such as populations, with floating-point numbers. Type casting enables you to do so directly.
2. The capability to compel data in one form to meet a different expectation — e.g. displaying the ASCII code of a `char` instead of the character itself.

## `auto` Declarations (C++11)

C++11 introduces a facility that allows the compiler to deduce a type from the type of
an initialization value. For this purpose it redefines the meaning of `auto`, a keyword dating
back to C, but one hardly ever used. Just use `auto` instead of the type name in an initializing declaration, and the compiler assigns the variable the same type as that of the initializer:

```cpp
auto n = 100;      // n is int
auto x = 1.5;      // x is double
auto y = 1.3e12L;  // y is long double
```

However, this automatic type deduction isn't really intended for such simple cases.
Indeed, you might even go astray. For example, suppose `x`, `y`, and `z` are all intended to be
type `double`. Consider the following code:

```cpp
auto x = 0.0;   // ok, x is double because 0.0 is double
double y = 0;   // ok, 0 automatically converted to 0.0
auto z = 0;     // oops, z is int because 0 is int
```

Using `0` instead of `0.0` doesn't cause problems with explicit typing, but it does with
automatic type conversion.

Automatic type deduction becomes much more useful when dealing with complicated
types, such as those in the STL (Standard Template Library). For example, C++98
code might have this:

```cpp
std::vector<double> scores;
std::vector<double>::iterator pv = scores.begin();
```

C++11 allows you to write this instead:

```cpp
std::vector<double> scores;
auto pv = scores.begin();
```

## Chapter Summary 

- C++'s basic types fall into two groups: integer types and floating-point types.
- Integer types, smallest to largest: `bool`, `char`, `signed char`, `unsigned char`, `short`, `unsigned short`, `int`, `unsigned int`, `long`, `unsigned long`, and (C++11) `long long`, `unsigned long long`. Exact sizes are implementation-dependent, but `short` is at least 16 bits and `long` is at least 32 bits, and `int` is at least as big as `short`.
- `wchar_t` holds any character in the extended character set; C++11 adds `char16_t` and `char32_t` for 16-bit and 32-bit character codes respectively.
- Characters are represented by their numeric codes; the I/O system determines whether a code is interpreted as a character or as a number.
- The three floating-point types are `float`, `double`, and `long double`, each guaranteed to be no larger than the next. Typically `float` uses 32 bits, `double` uses 64 bits, and `long double` uses 80 to 128 bits.
- C++ uses operators to provide the usual arithmetic support (addition, subtraction, multiplication, division, modulus); precedence and associativity rules determine which operation happens first when operators compete for the same value.
- C++ converts values from one type to another when you assign values to a variable, mix types in arithmetic, and use type casts to force type conversions. Many conversions are "safe" (no data loss), such as `int` → `long`; others, such as floating-point → integer, require more care.