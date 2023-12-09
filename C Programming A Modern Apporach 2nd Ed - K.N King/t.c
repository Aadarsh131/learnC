#include <stdio.h>
#include <limits.h>

int main()
{
    char *a = "adfkslfkdf \n jlakjsdkf \
// sisljdf";

    int *b = &a;

    printf("%p and %p", b,a);
    // printf(a);

    // int b = 45;
    // int *a = &b;
    // printf(a);
}