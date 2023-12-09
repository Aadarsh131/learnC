# Topic Covered
- [&check;] [5.1 Logical Expressions](#51-logical-expressions)
- [&cross;] [5.2 The if statement](#52-the-if-statement)
<hr>

■ **Selection Statements**- The `if` and `switch` statements allow a program to
select a particular execution path from a set of alternatives.  
■ **Iteration statements**- The `while` , `do`, and `for` statements support iteration
(looping).  
■ **Jump statements**- The `break` , `continue` , and `goto` statements cause an
unconditional jump to some other place in the program.


# 5.1 Logical Expressions

## Relational Operators
> `>` , `<` , `>=`, `<=`  

comparison between different datatypes are allowed. Result is either `0` or `1` (*NOTE:* there is no Boolean dataype in C)
 - precedence of "Relational Operators" is less than "Arithmetic Operators"

hence, expression `i + j < k + 1` is evaluated as `(i + j) < (k + 1)`, because 

## Equality Operator
>`==`, `!=`  

- precedence of "Equality operator" is less than "Relational operator"

hence, expression `i < j == j < k` is evaluated as `(i < j) == (j < k)`

## Logical Operator
> `!`, `&&` , `||`

same as the logical operators in Mathematics  

**Short Circuiting**- 
Both `&&` and `||` perform *short-circuit* evaluation of their operands.  
eg. In the exp `(i != 0) && (j/i > 0)`, if `i = 0`, then, because of short-circuit the next statement `(j/i > 0)` would not execute (*NOTE- This is very helpful, notice what would happen if there is no short-circuit, a divide by zero evaluation*)

- `!` has same precedence as unary plus and minus. And is `Right  associative`
- `&&`, `||` precedence is lower than "Relational operator" and "Equality operator". And is `Left associative`.

# 5.2 The `if` Statement
```c
if (a == b) //C interprets all non-zero values as `true`
{
    printf("Equal");
}

if (a = 10){ // NOTE: `=` will set the value to 10 and the check would be whether it is a non-zero value, which would always be `true`
    printf("Alway true");
}
```

## The `else` clause
```c 
if (expression) statement else statement
```
`else` would only execute if the `if` expression value is `0`

## Cascaded `if`
Testing a series of condition until one of the condition is true. 

```c
if (n == 0)
    printf("n is equal to 0\n");
else
    if (n == 1)
        printf("n is equal to 1\n");
    else 
        if (n == 2)
            printf("n is equal to 2\n");
        else 
        // and so on
```
above program can also be written as- (this way of identing the cascaded `if` statement avoids the problem of excessive indentation)
>`NOTE:` cascaded `if` statement isn't some new kind of statement, its just the ordinary `if else` but with nesting
```c
if (n == 0)
    printf("n is equal to 0\n");
else if (n == 1)
    printf("n is equal to 1\n");
else if (n == 2)
    printf("n is equal to 2\n");
else  //this last else need not be present
```

## The "Dangling else" problem
To which `if` statement does the `else` clause belong?
```c
if (y != 0)
    if (x != 0)
        result = x / y;
else
    printf("Error: y is equal to 0\n");
```
`else` clause in C doesn't care about the identation and would prefer to stick with the nearest `if` statement that hasn't alreay been paired. So, a correctly indented version would look like: 
```c
if (y != 0)
    if (x != 0)
        result = x / y;
    else
        printf("Error: y is equal to 0\n");
```
To make the `else` clause part of the outer `if` statement, we can enclose the inner `if` statement in braces: *(this example illustrates the value of using braces)*
```c
if (y != 0){
    if (x != 0)
        result = x / y;
} else
    printf("Error: y is equal to 0\n");
```

## Conditional expression

```c
expr1 ? expr2 : expr3
```
These conditional operators are also known as `ternary operator` (as they take 3 operands)

eg.
```c
return i > j ? i : j;
```

## Boolean values in C89
For many years, the C language lacked a proper Boolean type, and there is none
defined in the C89 standard. This omission is a minor annoyance, since many programs need variables that can store either false or true. One way to work around
this limitation of C89 is to declare an int variable and then assign it either 0 or 1:
```c
int flag;
flag = 0; //false
flag = 1; //true
```
It works, but the readability isn't improved, hence a better alternative is to define a macro-  

```c
#define TRUE 1
#define False 0
```
**NOTE:** ``` if (Flag == TRUE)``` would not work for all condition. Another better way is to write ```if (Flag)``` (will also check values other than 0 or 1)

Going one step further, we can define the macro for particular datatype-

```c
#define BOOL int // values defined with `BOOL` will internally gets converted to `int`

...

BOOL flag; //`BOOL` now clearifies what we want to store, a boolean value!
```
Later chapters will unfold more interesting way to set up a boolean type in C89 by using type definitions and enumerations.

## Boolean value in C99
The longstanding lack of Boolean type has been remedied in C99. C99 provides `_Bool` type.
```c
_Bool flag;
```
`_Bool` is an unsigned integer type, but it can only store `0` or `1`. An attempt to store a non-zero value would result in storing a value `1` instead, eg-

```c
flag = 5; // flag is assigned 1 (as it is of type _Bool)
```

C99 also provides a new header `<stdbool.h>` that makes it easier to work with boolean values, it provides a macro `bool` and macros `true` and `false` which stands for `1` and `0` resp.
```c
bool flag; // same as _Bool
flag = false;
flag = true;
```

# 5.3 The `switch` statement

A `switch` statement is easier to read than cascaded `if` statement. Moreover, `switch` are often faster than `if` statements, especially when their are many conditions.

```
switch (expression) {
    case constant-expression : statements
    ...
    ...
    case constant-expression : statements
    default : statements
}
```
The `switch` statement is fairly complex; let’s look at its components one by one:

- **Controlling expression**- must be an integer expression (chars are treated as integers in C)
- **Case Labels**-   
    - must be an integer  
    - cannot be a variable or function call   
    - can not be duplicates
    - several case labels can follow same statement
    - Unfortunately, there is no way to specify a range of values
    - default case doesn't need to come last
    - a default case is not compulsory
- **Statements**- ends with a *break*

```c
switch (grade) {
  case 4:
  case 3:
  case 2:
  case 1:  printf("Passing");
           break;
  case 0:  printf("Failing");
           break;
  default: printf("Illegal grade");
           break;
}
```
Or
```c
switch (grade) {
  case 4: case 3: case 2: case 1:
          printf("Passing");
          break;

  case 0: printf("Failing");
          break;

  default:printf("Illegal grade");
          break;
```

