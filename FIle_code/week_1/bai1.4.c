#include<stdio.h>
int tach_nguyen(double a){
    int b = (int)a;
    if (b-a >= 0.5){
        return b-1;
    }
    else{
        return b;
    }
    
}

int main(){
    double a;
    scanf("%lf", &a);
    printf("phan nguyen: %d", tach_nguyen(a));
    printf("\nphan thap phan: %.3lf",a-tach_nguyen(a));
}