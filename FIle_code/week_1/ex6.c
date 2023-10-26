#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long integer(double a){
    long long inte = (long long) a;
    return inte; 
}

int fraction(double a){
    char frac[100];
    sprintf(frac, "%f",a);
    char frac2[100]; 
    strcpy(frac2,strchr(frac,','));
    int test;
    sscanf(frac2,"%d",&test);
    return test;
}

int main(){
    double a = 3445.55555555543;
    printf("Integer: %lld \n",integer(a));
    printf("fraction: %d",fraction(a));
    return 0;
}