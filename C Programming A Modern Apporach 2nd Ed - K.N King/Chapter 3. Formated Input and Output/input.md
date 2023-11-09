# Topics covered  


- [&cross;] [3.1 The printf function](#)
- [&check;] [3.2 The scanf function](#32-the-scanf-function)
- [&cross;] [Q/A and problems](#)
<hr>

# 3.2 The scanf function
- ### Example 1.
  ```c
  #include <stdio.h>
  
  int main()
  {
      int a, b;
      float c, d;
      scanf("%d%d%f%f", &a, &b, &c, &d);
      printf("%d %d %f %f", a, b, c, d);
  }
  ////////////INPUT////////////
  /*
    1
  -29    .3
      -4.0e3
  */
  
  /*
  How compiler will process it-
  
  ##1%-29#####.3%#####-4.0e3% 
  srsrrrsssssrrssssssrrrrrr    (s: skipped, r: read)
  (where # is the white space and % is newline)
  
  scanf 'peaks' at the final newline character without actually reading it. This newline will be the first character read by the next call of scanf.
  */
  ```
  >**<u>INPUT-</u>**  
  >1-20.3-4.0e3
  >
  > ### How compiler will process it- 
  >- **Conversion specification: %d.** The first nonblank input character is `1`; since integers can begin with `1`, `scanf` then reads the next character, `-`. Recogniz­ing that `-` can’t appear inside an integer, `scanf` stores `1` into `a` and puts the `-` character back.
  >
  > - **Conversion specification: %d.** `scanf` then reads the characters `-` , `2`, `0`, and `.`(period). Since an integer can’t contain a decimal point, `scanf` stores `-20` into `b` and puts the `.` character back.
  >
  >- **Conversion specification: %f.** `scanf` reads the characters `.`, `3`, and `-` . Since a floating-point number can’t contain a minus sign after a digit, `scanf` stores `0.3` into `c` and puts the `-` character back.
  >- **Conversion specification: %f.** Lastly, `scanf` reads the characters `-`, `4`, `.`, `0`, `e`, `3`, and `\n` (new-line). Since a floating-point number can’t contain a new-line `\n` character, scanf stores `-4.0 x 10**3` into `d` and puts the new-line character back.
  >
  > Since the new-line character wasn't read, it will
  be left for the next call of `scanf`.
  <hr>
  <br>

- ### Example 2-
  ```c
  scanf("%d/%d",&a,&b);
  ```
  
  > **<u> INPUT </u>-**  
  > **#5#/#96** (where **#** is the whitespace)
  >
  > ### How compiler will process it- 
  >`scanf` will skip first whitespace while looking for an integer, matches `%d` with `5`, then attempt to match `/` in the format string with a space in the input. There's no match, so `scanf` puts the space back and `#/#96` would remain to be read by the next call of `scanf`.
  >
  >To allow spaces after the first number, we have to use the format string `"%d /%d"` instead.


- ### Example 3-
  `scanf` differs from `printf` in their string format implementation. `scanf` will ignore the whitespaces.
  ```c
  scanf("%d, %d",&a,&b); //lets say we mistake scanf with printf and applied a `,` in the format string 
  ```
  >compiler will look for a match of `,` immediatly after the input `a`, and a normal input string without a proper matching of `,` would not work. In our case input string of "`#,96`" (where # is whitespace) would not work and "`#,96`" would be left out for the next call to `scanf` (best way is to simply use `"%d%d%d..."` without spacing) for multiple input values.  
  But we can use the left "`#,96`" in the next immediate call of `scanf` like this-  
  >

  > **<u>Input String</u>**-  
  > 5%#%%,96#7 (where # is whitespace, % is newline)
  >```c
  >scanf("%d,%d",&a,&b);
  >//we know that our input string is going to be something of the form "<num><any no. of space/newline>,96<num>", hence we can use the left out part (",96") in the next scanf like this-
  >scanf(" ,96%d",&c); //NOTE: ",96%d" i,e, without whitespace would not work
  >//also,
  >" ,96  %d" is valid
  >"\n\t  ,96\n %d" is valid
  >//in general, any blank character before or after ",96"(which was left out from the 1st scanf) is valid
  >```
  > **<u>Output</u>**-   
  > a = 5  
  > b = garbage  
  > c = 7
  >
  
  >### Sample results-
  > ```c
  >scanf("%d, %d", &i, &a);
  >scanf("\n,96 %d", &a);
  >printf("%d%d",i,a);
  >```
  > |Input String(where, % is newline, # is whitespace)| **Output**|
  > |---| ---|
  >5%,96-7  | i = 5 and  a = -7 
  >5#,967 | i = 5 and a = 7
  >5##%#,96%#5 | i = 5 and a = 5
  >5,96%3 | i = 5 and a = 96

  >**NOTE**-  
  >```c
  >scanf("%d%d\n", &a,&b); //notice the `\n` at the end
  >```
  >Will cause an interactive program to hang until the user enters a *nonblank* character.
  >
  >```c
  >scanf("%d%d\n", &a,&b);
  >scanf("%d",&c);
  >```
  > would work because the needed *nonblock* character is now entered from the 2nd `scanf` 
  
## Adding Fractions
 ```c
#include <stdio.h>

int main()
{
    int numerator1, numerator2, denom1, denom2;
    printf("Enter first fraction: ");
    scanf("%d/%d", &numerator1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &numerator2, &denom2);

    printf("The sum is %d/%d", (numerator1 * denom2 + numerator2 * denom1), (denom1 * denom2)); //NOTE: the fraction is not reduced to the lowest terms
}
 ``` 

