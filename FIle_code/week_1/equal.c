#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[n], b[m];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
        }

        int equal = (n == m && memcmp(a, b, n * sizeof(int)) == 0); // Test hàm mới đọc được XD , bộ test ở mức nhỏ 
        // nhưng thôi cứ thử 
        // 165ms
        printf("%d\n", equal);
    }

    return 0;
}
