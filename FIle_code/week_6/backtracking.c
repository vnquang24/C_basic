#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *a, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void permute(int *a, int l, int r) {
    if (l == r) {
        printArray(a, r+1);
    } else {
        for (int i = l; i <= r; i++) {
            if (l != i && a[l] == a[i]) continue;
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); // backtrack
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    permute(arr, 0, n-1);
    return 0;
}