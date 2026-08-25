## C++ Statements

### Declaration Statements and Variables

To store an item of information in a computer, you must identify both the storage location and how much memory
storage space the information requires. One way to do this is to use a *declaration statement* to indicate the
type of storage and to provide the label for the location.

- Ex (using [carrots.cpp](programs/chapter-2/carrots/carrots.cpp) program)

```cpp
int carrots;
```

This statement provides two kinds of information: the type of memory storage needed and a label to attach to
that storage.

### Assignment Statements

An assignment statement assigns a value to a storage location.

- Ex ([carrots.cpp](programs/chapter-2/carrots/carrots.cpp))

This statement assigns the integer `25` to the location `carrot`.

```cpp
carrots = 25;
```

The `=` symbol is called the *assignment operator*. You can use this operator serially.

```cpp
int steinway;
int baldwin;
int yamaha;
yamaha = baldwin = steinway = 88;
```

The assignment works from right to left. First, `88` is assigned to `steinway`; then the value of `steinway`,
which is now `88`, is assigned to `baldwin`; then `baldwin`'s value of `88` is assigned to `yamaha`.

### A New Trick for **cout**

`cout` works with both strings and integers. Keep in mind that the integer *25* is quite different from the
string *"25"*. The string holds the characters with which you write the number (char `'2'` and char `'5'`).
The program internally stores the numeric codes for both chars. To print the string, `cout` simply prints each
char in the string. But the integer is stored as a numeric value; the computer stores it as a binary number.

`cout` must translate a number in integer form into characters before it can print it.

The intelligent way in which `cout` behaves stems from C++'s object-oriented features: the *insertion operator*
(`<<`) adjusts its behavior to fit the type of data that follows it.