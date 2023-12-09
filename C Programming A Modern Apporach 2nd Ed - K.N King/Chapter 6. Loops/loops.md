# Topics covered
- [&cross;] [6.1 The while statement](#) **??**
- [&cross;] [6.2 The do statement](#) **??**
- [&check;] [6.3 The for statement](#the-for-statement) 
- [&check;] [6.4 Exiting from a loop](#64-exiting-from-a-loop)
- [&check;] [6.5 The Null statement](#65-the-null-statement)

Symbols-

- **?** - skipped (havn't touched)
- **??** - skimmed (found nothing so interesting to note down)
<hr>

# 6.3 The *for* statement

## The comma operator

Let `i=1` and `j=5`, value of i and j after the expression ``++i, i+j`` would be `i=2` and `j=7`

"**,**" operator is left associative and its precedence is very low

so, the compiler will execute the expression ```i = 1, j = 2, k = i+j``` as ```((i=1), (j=2), (k=i+j))``` left to right

The comma operator allows us to glue two expressions together to form a single expression, generally found in `for` loop statements

# 6.4 Exiting from a loop 

## The *break* statement
*break* statement transfers control out of the innermost enclosing while,do while, for, or switch statement

## The *continue* statement
*break* transfers control just past the end of the loop, whereas *continue* transfers the control just before the end of the loop (with *break* control leaves the loop, with *continue* control remains inside the loop)

- *continue* is limited to loops
```c
while (i < 10){
    if (i == 0){
        i++;
        continue;
    }
    if (i == 5)
        break;

    sum += i;
    i++;
    /* continue jumps to here */
}   /* break jumps here (out of loop) */
```
## The *goto* statement
``goto identifier;``

``identifier : statement``  

Executing the statement `goto L;` transfers control to the statement that follows
the label `L`, which must be in the same function as the `goto` statement itself.

Important usecase of `goto` is when exiting from a nested loop- 
```c
while (..){
    switch (..){
        ...
        goto loop_done; // "break" would not let us to exit from "while" loop in this case
        ...
    }
}
loop_done: ...
```
# 6.5 The Null statement
```c
for (d = 2; d < n && n % d != 0; d++); //colon at the end is a null statement
```