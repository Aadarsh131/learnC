# Topics Covered

- ... **?**
- ... **?**
- ... **?**
- [&check;] [7.4 Type Conversion](#74-type-conversion)
- [&check;] [7.5 Type Definitions](#75-type-definitions)
- ... **??**

Symbols-
- **?** - skipped (havn't touched)
- **??** - skimmed (found nothing so interesting to note down)
<hr>

# 7.4 Type Conversion

## Casting

`(type-name) expression`

In C, `(type-name)` is considered as unary operator

```c
long i;
int j = 1000;

i = j * j; /* Overflow may occur */
```
using a cast avoids the problem
```c
i = (long) j * j; //Or, i = j * (long) j; //OR, i = (long) j * (long) j;

// Since, cast operator's precedence is higher than *, the expression is executed internaly by the compiler as this:    i = ((long) j) *j
//forcing the second j to be converted to long as well (implicit coversion)
```
> **NOTE:**  
>```c
>i = (long) (j * j); //WRONG
>```
> would be wrong, as overflow would have already occured by the time of the cast.


# 7.5 Type Definitions

using macro-
```c
#define BOOL int
```
using type definition- 
```c
typedef int Bool //convention to use first letter capital
```

## Type definition and portability
On average machines-
```c
typedef int Quantity;
```
When we transport the program to a machine with shorter integers, w e’ll change the definition of Quantity :
```c
typedef long Quantity;
```
The C library itself uses typedef to create names for types that can vary from one C implementation to another; these types often have names that end with `_t` , such as `ptrdiff_t`, `size_t`, `wchar_t` and `int32_t` (with exactly 32 bits).

