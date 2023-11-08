## 1.1 Getting Started 
```c
printf("hello, world
");
//Error because of incomplete string, C compiler expects a string on a single line 
```

- `\n` for newline, `\t` for tab, `\b` for backspace, `\"` for double quotes, `\\` for backslash itself
    ```c
    printf("\"hello\", \\world\\\n"); //"hello", \world\
    ```
    ```c
    printf("12345");    // Output: 12345
    printf("\b");       // Moves the cursor back one position
    printf("X");        // Overwrites the '5' with 'X', so the output will be: 1234X
    ```
#### Exercise 1-2.
- Experimenting with Other backslash sequence
    ```c
    printf("Dear,\fAadarsh");
    /*
    Dear,
         Aadarsh
    */
    ```
    ```c
    printf("\eLmao"); //mao
    ```
    ```c
    printf("Cool\aYeah");//CoolYeah
    ```
    ```c
    printf("An a\pp\le a \da\y"); //An apple a day
    ```
`printf` is not part of the C language; there is no input or output defined in C itself. `printf` is just a useful function from the standard library of functions that are normally accessible to C programs.The behavior of `printf` is defined in the "ANSI standard", however, so its properties should be the same with any compiler and library that conforms to the standard.

## 1.2 Variables and Arithmetic Expressions
```c
#include <stdio.h>

int main()
{
    int celcius, fahr;
    fahr = 0;
    while (fahr <= 300)
    {
        celcius = 5 * (fahr - 32) / 9;
        printf("%d %d\n", celcius, fahr); // output isn't pretty, numbers are not right justified
        printf("%3d %3d\n", celcius, fahr); // right justified to 3 digit wide
        fahr += 20;
    }
    return 0;
}
```
Above program with more accurate result(using floating point numbers)- 
```c
#include <stdio.h>

int main()
{
    float celcius, fahr;
    int lower = 0;
    int upper = 300;
    fahr = lower;         //  int to float(implicit conversion)
    while (fahr <= upper) //  int to float(implicit conversion)
    {
        celcius = (5.0 / 9.0) * (fahr - 32);    // Note: division of Int and Float point numbers is always Float
        printf("%3.0f %6.2f\n", celcius, fahr); // We estimated our total character length before, after and including the decimal, which in our case was 6 at max(3 before and 2[as specified] after the decimal) hence we used 6 in %6.2f, 6 specifies the total length. eg, `140.00` is 6 digit char long incl. the '.'.

        fahr += 20                              // int to float(implicit conversion)
    }
    return 0;
}
```

>|Format specifier| Action|
>|---|---|
>|`%d`	|    print as decimal integer  |
>|`%6d`|	print as decimal integer, at least 6 characters wide  
>|`%f`	|    print as floating point  
>|`%6f`|	print as floating point, at least 6 characters wide  
>|`%.2f`|	print as floating point, 2 characters after decimal point  
>|`%6.2f`|	print as floating point, at least 6 wide and 2 after decimal point  

- `%o` for octal
- `%x` for hexadecimal
- `%c` for character
- `%s` for character string
- `%%` for `%` itself

## 1.3 The For statement (loop)
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */
main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

## 1.4 Symbolic Constants
```c
#define name replacementText
```
```c
#include <stdio.h>

//conventinally the symbolic constant names are UpperCase
#define   LOWER  0       /* lower limit of table */
#define   UPPER  300     /* upper limit */
#define   STEP   20      /* step size */

/* print Fahrenheit-Celsius table */
main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) 
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

## 1.5 Character Input and Output
The model of input and output supported by the standard library is very simple. Text input or output, regardless of where it originates or where it goes to, is dealt with as streams of character. A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character. It is the responsibility of the library to make each input or output stream conform to this model.
```c
int c = getchar(); // reads next input character from a text stream (usually comes from keyboard or files) and return that as its value

putchar(c);        // prints a character
```
- ### 1.5.1 File Copying

    Each keyboard character is converted to its bit pattern by the compiler, generally we use `char` type to store it, But we can use `int` as well
    ```c
    #include <stdio.h> //EOF is defined here

    /* 1st version */
    main()
    {
        int c;

        c = getchar();
        // EOF- "End of file" is a character that is different from the real characters
        while (c != EOF) { //EOF doesnot store `char` type values hence comparing it with a `int` type
            putchar(c);
            c = getchar();
        }
    }
    ```    

    `c = getchar()` is an expression and has a value, which is the value of the left hand side after the assignment. This means that an assignment can appear as part of a larger expression. Hence we can do-
    ```c
    /* 2nd version */
    main()
    {
        int c;
        while ((c = getchar()) != EOF) //precedence of '!=' is greater than of '=', hence a () is required 
            putchar(c); 
    }
    ```
    #### Exercise 1-7.
    ```c
    printf("The value of EOF is: %d\n", EOF); // The value of EOF is: -1
    ```
- ### 1.5.2 Character counting 
    ```c
    #include <stdio.h>

    /* count characters in input; 1st version */
    main()
    {
        long nc; //greater than int capacity

        nc = 0;
        while (getchar() != EOF)
            ++nc;
        printf("%ld\n", nc);
    }
    ```
    ```c
    #include <stdio.h>

    /* count characters in input; 2nd version */
    main()
    {
        double nc;

        for (nc = 0; getchar() != EOF; ++nc)
            ; //null statement
        printf("%.0f\n", nc); //%f for both floats and doubles
    }
   ```
- ### 1.5.3 Line Counting
    Counting lines is just counting newlines from the input text stream.
    ```c
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') // '\n' ASCII value is 10
    //NOTE: ′\n′ is a single character, and in expressions is just an integer; on the other hand, "\n" is a `string constant` that happens to contain only one character. Both are different.

    //printf("%d and %d", '\n',"\n"); // second %d will output the memory address of "\n"(maybe that is garbage UB) 
    //printf("%d and %d",'\n',"\n"[0]); //same

            ++nl;
    printf("%d\n", nl);
    ```
    **Character Constant** - numeric value of a character (stored in machine's character set). So, for example, ′A′ is a character constant; in the ASCII character set its value is 65

- ### 1.5.4 Word Counting
    ```c
    #include <stdio.h>

    #define OUT 0
    #define IN 1

    main()
    {
        int nl, nw, nc = 0; //equals nl = (nw = (nc = 0)); where the expression values are stored from R to L
        int state = OUT;
        int c;
        while (((c = getchar()) != EOF))
        {
            ++nc;
            if (c == '\n')
                ++nl;
            if (c == ' ' || c == '\t' || c == '\n')
                state = OUT;
            else if (state == OUT)
            {
                state = IN;
                ++nw;
            }
        }
        printf("%d %d %d\n", nl, nw, nc);
    }
    ```
## 1.6 Arrays
```c
#include <stdio.h>

/* count digits, white space, others */
main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != 'A')
        // this Only checks whether the input character is is a number
        if (c >= '0' && c <= '9')

            // here arr[char] will implicitly gets converted to arr[n] where 'n' is the corresponding ASCII decimal value of character 'char'
            ++ndigit[c - '0']; // as ASCII value of '0' is 48, so eg, if c='5', then ndigit['5'-'0']=ndigit['53'-'48']=ndigit[5] 
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
           nwhite, nother);

}
```