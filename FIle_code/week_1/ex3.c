#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void replace(char *string,char c1,char c2){
	int i;
	for (i=0;i <= strlen(string);i++){
		if (string[i] == c1){
			string[i] = c2;
		}
	}
}
int main(int argc, char *argv[]) {
	char str[1000];
	char a;
	char b;
	scanf("%s %c %c",&str,&a,&b);
	replace(str,a,b);
	printf("%s",str);
	return 0;
}
