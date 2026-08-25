## C++ Initiation

Let's begin with a simple C++ program that displays a message: [**`myfirst.cpp`**](../programs/chapter-1/myfirst/myfirst.cpp)
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

### The C++ Preprocessor and the **iostream** File

If your program is to use the usual C++ input or output facilities, you provide these two lines:

```cpp
#include <iostream>
using namespace std;
```

C++ uses a *preprocessor*. This is a program that processes a source file before the main compilation
takes place. You don't have to do anything special to invoke this preprocessor. It automatically operates
when you compile the program:

```cpp
#include <iostream>  // a PREPROCESSOR directive
```

This directive causes the preprocessor to add the contents of the `iostream` file to your program. This is
a typical preprocessor action: adding or replacing text in the source text before it's compiled.

**Why should I add the contents of the iostream file to the program?**
- Communication between the program and the outside world.

The `io` in `iostream` refers to *input*, and to *output*. The `#include` directive causes the contents of the
`iostream` file to be sent along with the contents of your file to the compiler.

In essence, the contents of the `iostream` file replace the `#include <iostream>` line in the program.

### Namespaces

If you use `iostream` instead of `iostream.h`, you should use the following namespace directive to make the
definitions in `iostream` available to your program:

```cpp
using namespace std;
```

This is called using a *directive*.

Namespace support is a C++ feature designed to simplify the writing of large programs and of programs that combine
pre-existing code from several vendors, and to help organize programs. One potential problem is that you might use
two prepackaged products that both have, say, a function called `wanda()`. The namespace facility lets a vendor
package its wares in a unit called a *namespace* so that you can use the name of a namespace to indicate which
vendor's product you want. So Microflop Inc. could place its definitions in a namespace called `Microflop`.
Then `Microflop::wanda()` would become the full name for its `wanda()` function.

Your program could now use the namespaces to discriminate between various versions:

```cpp
Microflop::wanda("go dancing?");        // use Microflop namespace version
Piscine::wanda("a fish named Desire");  // use Piscine namespace version
```

In this spirit, the classes, functions, and variables that are standard components of C++ compilers are now placed
in a namespace called `std`. This takes place in the *h-free* header files. Thus, you can omit the `using`
directive and, instead, code in the following style:

```cpp
std::cout << "Come up and C++ me some time.";
std::cout << std::endl;
```

The following line means you can use names defined in the `std` namespace without using the `std::` prefix:

```cpp
using namespace std;
```

This `using` directive makes all the names in the `std` namespace **available**. Modern practice regards this as
a bit lazy and potentially a problem in large projects. The preferred approaches are to use the `std::` qualifier
or to use something called a *using declaration* to make just particular names available:

```cpp
using std::cout;        // make cout available
using std::endl;        // make endl available
using std::cin;         // make cin available
```

### C++ Output with `cout`

The `<<` notation indicates that the statement is sending the string to `cout`; the symbols point the way the
information flows. And, what is `cout`? It's a predefined object that knows how to display a variety of things,
including strings, numbers, and individual characters.

You don't have to know the innards of an object in order to use it. All you must know is its interface — that is,
how to use it. The `cout` object has a simple interface. If `string` represents a string, you can do the following
to display it:

```cpp
cout << string;
```

The `cout` object, whose properties are defined in the `iostream` file, represents that stream. The object
properties for `cout` include an insertion operator (`<<`) that inserts the information on its right into the
stream.

```cpp
cout << "Come up and C++ me some time.";
```

It inserts the string "Come up and C++ me some time." into the output stream.

**The Manipulator *endl***

`endl` is a special C++ notation that represents the important concept of beginning a new line. Inserting `endl`
into the output stream causes the screen cursor to move to the beginning of the next line. Special notations like
`endl` that have particular meanings to `cout` are dubbed *manipulators*. Like `cout`, `endl` is defined in the
`iostream` header file and is part of the `std` namespace.

Note that the `cout` facility does not move automatically to the next line when it prints a string.

**The newline Character**

C++ has another, more ancient, way to indicate a new line in output: `\n`

```cpp
cout << "What's next? \n";   // \n means start a new line
```

The `\n` combination is considered to be a single character called the *newline* character. You can use it when
you need less typing when displaying a string, or to make a newline by itself:

```cpp
cout << "Pluto is a dwarf planet. \n";
cout << "Pluto is a dwarf planet" << endl;
// either way both print the text, and go to the next line

cout << "\n";
cout << endl;
// both start a new line
```