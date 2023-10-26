#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* noi_chuoi(const char *s1,const char *s2){
    char* s = (char *)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
        if (s == NULL) {return 0;}
    int i;
    for(i=0;i < strlen(s1);i++){
        s[i] = s1[i]; 
    }
    int j;
    for(j=0;j < strlen(s2);j++){
        s[i+j] = s2[j];
    }
    s[i+j] = '\0';
    // free(s);
    return s;
}
// Nếu free trong hàm trước return thì vẫn ra kết quả đúng do trên vùng bộ nhớ mà cái s chỉ đến vẫn còn dữ liệu
// Chỉ cần ghi đè lên phần dữ liệu đó bằng 1 hàm int hoặc thao tác bộ nhớ là khiến dữ liệu biến mất
int main(){
    char* s1[100];char* s2[100];
    char *p = noi_chuoi(s1,s2);
    if (p == NULL) {return 0;}
    scanf("%s",s1);
    scanf("%s",s2);
    printf("%s",p);
    free(p);   
    return 0;
}