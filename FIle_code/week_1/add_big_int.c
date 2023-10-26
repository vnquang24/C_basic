#include <stdio.h>
#include <string.h>
// Trở về tuổi thơ , cộng như hồi tiểu học XD

void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
void addLargeNumbers(char num1[], char num2[], char result[]) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLength = (len1 > len2) ? len1 : len2;

    reverseString(num1);
    reverseString(num2);

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[i] = (sum % 10) + '0';
    }

    if (carry > 0) {
        result[maxLength] = carry + '0';
        result[maxLength + 1] = '\0';
    } else {
        result[maxLength] = '\0';
    }

    reverseString(result);
}

int main() {
    char num1[100], num2[100], result[101];

    scanf("%s %s", num1,num2);
    addLargeNumbers(num1, num2, result);
    printf("%s", result);

    return 0;
}
