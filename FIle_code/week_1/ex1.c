#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char A[1000];
	fgets(A,1000,stdin);
	int cou[129];
	int i = 0;
	for(i=0;i <= 129;i++){
		cou[i] = 0;
	}
	for(i=0;i <= strlen(A);i++){
         cou[A[i]]++;
	}
	for(i=97;i <= 122;i++){
		if (cou[i] != 0){
			printf("The letter '%c' appears %d times \n",i,cou[i]);
		}
	}
	return 0;
}
