#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }
    double S = atof(argv[1]) * atof(argv[2]);
    printf("S = %lf", S);
    return 0;
}