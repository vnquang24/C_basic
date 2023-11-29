
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[100], s2[100];
    scanf("%s",s1);
    scanf("%s",s2);
    char s[strlen(s1)+strlen(s2)+1];
    int i;
    for(i=0;i < strlen(s1);i++){
        s[i] = s1[i]; 
    }
    int j;
    for(j=0;j < strlen(s2);j++){
        s[i+j] = s2[j];
    }
    s[i+j] = '\0';
    printf("%s",s);   
}