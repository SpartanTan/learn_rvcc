#include <stdio.h>
#include <stdlib.h>

// Programe takes input like "1-2+3"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s: invalid number of arguments\n", argv[0]);
        return 1;
    }

    char *P = argv[1];
    // declare the global main
    printf("  .global main\n");
    // main tag
    printf("main:\n");

    // get the first number from string
    printf("  li a0, %ld\n", strtol(P, &P, 10)); // 10 means using decimal system
    // Now the pointer P points to the start of a string stores "-2+3"
    // *P fetches the first character in this string

    while (*P)
    {
        if (*P == '+')
        {
            // resolve operator
            ++P; // Moves the pointer to the next character
            // "addi rd, rs1, imm" means "rd = rs1 + imm"
            printf("  addi a0, a0, %ld\n", strtol(P, &P, 10));
            continue;
        }
        if (*P == '-')
        {
            ++P;
            printf("  addi a0, a0, -%ld\n", strtol(P, &P, 10));
            continue;
        }

        fprintf(stderr, "unexpected character: '%c'\n", *P);
        return 1;
    }
    printf("  ret\n");

    return 0;
}