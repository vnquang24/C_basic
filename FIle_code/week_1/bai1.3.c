#include<stdio.h>

int main(){
    char str[100];
    fgets(str, 100, stdin);
    char a,b;
    scanf("%c %c", &a, &b);
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] == a){
            str[i] = b;
        }
    }
    printf("%s", str);
}