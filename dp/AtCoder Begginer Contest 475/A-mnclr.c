// https://atcoder.jp/contests/abc475/tasks/abc475_a
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[11];
    scanf("%s", s);

    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        printf("%c", s[i]);

        if (i != n - 1) {
            printf("o");
        }
    }

    return 0;
}