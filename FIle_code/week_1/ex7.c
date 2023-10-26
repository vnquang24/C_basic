#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void replace(char *string,char c1,char c2){
	while (*string)
    {
        if (*string == c1){
            *string = c2; 
		}
		string++;
    }
    
}

int main(int argc, char *argv[]) {
	char str[1000];
	char a;
	char b;
	printf("Nhap chuoi can thay the: \n");
	fflush(stdin);
	fgets(str,1000,stdin);
    str[strlen(str)-1] = '\0';
	fflush(stdin);
	printf("Nhap ki tu can thay the: "),scanf("%c",&a);
	fflush(stdin);
	printf("Nhap ki tu thay the: ");scanf("%c",&b);
	replace(str,a,b);
	printf("%s",str);
	return 0;
}