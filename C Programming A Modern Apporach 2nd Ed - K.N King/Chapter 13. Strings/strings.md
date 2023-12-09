# Topics Covered

- [&check;] [13.1 String Literals]

Symbols-
- **?** - skipped (havn't touched)
- **??** - skimmed (found nothing so interesting to note down)
<hr>

# 13.1 String Literals

## Continuing a String Literal

```c
printf("learning about string \
literals here"); //a "\" at the end of the line to keep continuing

//NOTE: "\" technique has one drawback: The string must continue at the beginning of the next line, thereby wrecking the program's indented structure
```
Better/Recommended way is-
```c
//Possible because of the Rule- "when two or more strings are adjacent, the compiler will join them into a single string"
printf("learning about string "
       "literals here");
```

## How string literals are stored
C treats string literals as character arrays.  
A string literal of length `n` would set asside a memory of `n+1` bytes for the string, one extra character `\0` to mark the end of string.  

The null character is a byte whose bits are all 0, hence represented as `\0` escape sequence. (ASCII code is also 0).

- "abc" is stored as array of 4 chars with values a, b, c and \0  
- "" is stored as array of 1 char with value \0 

String literals is treated as `char *` by the compiler.  
Both `printf` and `scanf` expects a value of type `char *` as their first argument

```c
char *a = "abc";

//Both way will work, as we have passed `char *` as expected by `printf`
printf(a); 
printf("abc"); // passed the addr of "abc" (pointer to where "a" is stored in the memory) 
```

## Operations on String literals

```c
char *p;
p = "abc"; // this would not copy, but it would point `p` to `a`
```
C allows pointers to be subscripted, hence we can subscript string literals




