#include<stdio.h>
struct list
{
    char data;
    struct list *link;
};

int main(){
    struct list a1,a2,a3;
    a1.data = 'a';
    a2.data = 'b';
    a3.data = 'c';
    a1.link = &a1;
    a1.link = a2.link;
    a2.link = a3.link;
    a3.link = NULL;
}