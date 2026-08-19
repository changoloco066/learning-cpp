## C++ Initiation

Let's begin with a simple C++ program that displays a message: **`myfirst.cpp`**.
It uses the C++ **`cout`** (spelled "see-out") facility to produce character output.

### Program Adjustments

You can make the window stay open until you strike a key by adding the following line
of code before the `return` statement:

```cpp
cin.get();
```

## C Input and Output

In C++ you can use all the standard C input and output functions, like `printf()` and
`scanf()`, provided that you include the usual C `stdio.h` file. But since this is a
C++ learning course, I'll be using C++'s input facilities, which improve in many ways
upon the C versions.

## Features of the main() Function

The sample program shown has the following fundamental structure:

```cpp
int main()
{
    statements
    return 0;
}
```

These lines state that there is a function called `main()`, and they constitute a *function definition*.
This definition has two parts: the first line `int main()`, called a *function header*, and the portion
enclosed in braces (`{` and `}`), which is the *function body*.

In C++ each complete instruction is called a *statement*. You must terminate each statement with a semicolon `;`.
The final statement in `main()`, called a *return statement*, terminates the function.

### The Function Header as an Interface

In general, a C++ function is activated, or *called*, by another function, and the function header describes the
interface between a function and the function that calls it. The part preceding the function name is called the
*function return type*; it describes information flow back to the function that calls it. The part within the
parentheses following the function name is called the *argument list* or *parameter list*; it describes information
flow from the calling function to the called function.

In short, the following function header states that the `main()` function returns an integer value to the function
that calls it and that `main()` takes no information from the function that calls it:

```cpp
int main()
```

Many existing programs use the classic C function header instead:

```cpp
main()      // original C style
```

Under classic C, omitting the return type is the same as saying that the function is type `int`. However, C++ has
phased out that usage. You can use this variant:

```cpp
int main(void) // very explicit style
```

Using the keyword `void` in the parentheses is an explicit way of saying that the function takes no arguments.
Under C++, leaving the parentheses empty is the same as using `void` in the parentheses.

Some programmers use this header and omit the return statement:

```cpp
void main()
```

A void return type means that the function doesn't return a value. However, although this variant works on some
systems, on others it fails. So you should avoid this form and use the C++ Standard form.

If the compiler reaches the end of `main()` without encountering a return statement, the effect will be the same
as if you ended `main()` with this statement:

```cpp
return 0;
```

**This implicit return is provided only for `main()` and not for any other function.**