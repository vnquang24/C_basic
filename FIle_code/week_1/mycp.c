#include<stdio.h>  

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    FILE *f1, *f2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "w");
    char c;
    while ((c = fgetc(f1)) != EOF){
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}