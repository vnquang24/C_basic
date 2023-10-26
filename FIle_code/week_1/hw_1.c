#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <number1> \n", argv[0]);
        return 1;
    }
        double e = exp(atof(argv[1]));
        printf("%lf",e);
    return 0;
}