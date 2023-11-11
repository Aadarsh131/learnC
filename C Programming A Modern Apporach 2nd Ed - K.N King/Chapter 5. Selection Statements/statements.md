# Topic Covered
- [&check;] [5.1 Logical Expressions](#51-logical-expressions)
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

