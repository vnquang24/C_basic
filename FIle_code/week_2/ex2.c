#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct point
{
    int x;
    int y;
} point_t;
typedef struct circle
{
    point_t center;
    double radius;
} circle_t;

int check(int x,int y, const circle_t *s){
    int tam = sqrt((x^2-(s -> center.x)^2) + (y^2-(s -> center.y)^2));
    if (tam <= s -> radius)
    {
        return 1;
    }
    else return 0;  
}
int main(){
   circle_t s;
   scanf("%d %d %lf",&s.center.x,&s.center.y,&s.radius);
   point_t temp;
   scanf("%d %d",&temp.x,&temp.y);
   printf("Diem thuoc vong tron : %d",check(temp.x,temp.y,&s));
   return 0;
}