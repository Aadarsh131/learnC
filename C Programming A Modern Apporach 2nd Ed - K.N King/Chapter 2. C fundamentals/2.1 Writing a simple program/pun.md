# Topics Covered
- [&check;] [2.1 Writing a Simple Program](#21-writing-a-simple-program)
- [&cross;] [2.2 The General Form of a Simple Program](#) (**very basic; not required**)
- [&cross;] [2.3 Comments](#) (**very basic; not required**)
- [&cross;] [2.4 Variables and Assignment](#) (**very basic; not required**)
- [&cross;] [2.5 Reading Input](#) (**very basic; not required**)
- [&cross;] [2.6 Defining names for Constants](#) (**very basic; not required**)
- [&cross;] [2.7 Identifiers](#) (**very basic; not required**)
- [&cross;] [2.8 Layout of a program](#) (**very basic; not required**)
- [&cross;] [Q/A, Exercise and Projects](#)
<hr>

# 2.1 Writing a Simple Program
## Compiling and Linking 
- **Preprocessing**- is done with the help of **preprocessor** (it is like an editor, it can add things to the program and do modifications). Commands that begins with `#` are  called *directives* which is processed by the preprocessors.

- **Compiling**- converts to object code

- **Linking**- ***linker*** combines the ( *object code*  + *additional library code* ) to make an executable program.  
eg. `printf` is a library (standard I/O lib) function that will be linked after the object code is generated.

> ## The GCC Compiler
> ```sh
>gcc -o pun pun.c #<compilername> -o <outputFilename> <progarmName>.c
>
>#or simply
>gcc pun.c #outputs executable file named `filename.out`
>```

