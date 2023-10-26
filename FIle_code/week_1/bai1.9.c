#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *file1 = fopen("input.txt", "r"); // Mở tệp đọc
    FILE *file2 = fopen("output.txt", "w"); // Mở tệp ghi

    if (file1 == NULL || file2 == NULL) {
        printf("Không thể mở tệp.\n");
        return 1;
    }

    char buffer[1024]; // Để lưu tạm dữ liệu từ tệp 1

    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        fputs(buffer, file2); // Ghi từng dòng vào tệp 2
    }

    // Đóng tệp
    fclose(file1);
    fclose(file2);
}