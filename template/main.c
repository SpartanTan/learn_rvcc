#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2){
        fprintf(stderr, "%s: invalid number of arguments\n", argv[0]);
        return 1;
    }
    
    // declare the global main
    printf("  .global main\n");
    // main tag
    printf("main:\n");
    
    return 0;
}