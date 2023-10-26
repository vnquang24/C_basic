#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int check_equal(int *a,int *b,int n){
	int i;
	int check = 1;
	for(i=0;i<=n;i++){
		if (a[i] != b[i]){
			check = 0;
			break;
		}
	}
	return check;
}
int main(int argc, char *argv[]) {
	int n1,n2;
    printf("So luong phan tu day 1: ");scanf("%d",&n1);
    printf("So luong phan tu day 2: ");scanf("%d",&n2);
    int arr1[n1];
    int arr2[n2];
    int i;
    printf("Nhap phan tu day 1:\n");
    for(i=0;i < n1;i++){
    	scanf("%d",&arr1[i]);
	}
	printf("Nhap phan tu day 2:\n");
	for(i=0;i < n2;i++){
		scanf("%d",&arr2[i]);
	}
	if (n1 != n2){
		printf("0");
	}
	else {
		if (check_equal(arr1,arr2,n1)){
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
