#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int hex_to_int(char c) {
    c = toupper(c);
    return (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
}

char int_to_hex(int n) {
    return n < 10 ? n + '0' : n - 10 + 'A';
}

int rgz() {
    setlocale(LC_ALL, "ru");
    char num1[100], num2[100];

    printf("Введите два числа через пробел: ");
    if (scanf("%99s %99s", num1, num2) != 2) {
        printf("Input error\n");
        return 1;
    }

    for (int i = 0; num1[i]; i++) num1[i] = toupper(num1[i]);
    for (int i = 0; num2[i]; i++) num2[i] = toupper(num2[i]);

    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);

    printf("Сложение:\n");
    printf("  %s\n", num1);
    printf("+ %s\n", num2);

    int max_len = (len1 > len2 ? len1 : len2);
    printf("  ");
    for (int i = 0; i < max_len + 1; i++) printf("-");
    printf("\n  ");

    int carry = 0;
    int sum[101] = { 0 };

    for (int i = 0; i < max_len || carry; i++) {
        int d1 = (i < len1) ? hex_to_int(num1[len1 - 1 - i]) : 0;
        int d2 = (i < len2) ? hex_to_int(num2[len2 - 1 - i]) : 0;
        int s = d1 + d2 + carry;
        sum[i] = s % 16;
        carry = s / 16;
    }

    int sum_len = 100;
    while (sum_len > 0 && sum[sum_len] == 0) sum_len--;

    for (int i = sum_len; i >= 0; i--) {
        printf("%c", int_to_hex(sum[i]));
    }
    printf("\n");

    printf("Умножение:\n");
    printf("%*s", len2, "");
    printf("  %s\n", num1);
    printf("%*s", len2, "");
    printf("* %s\n", num2);

    int total_len = len1 + len2;
    printf("  ");
    for (int i = 0; i < total_len + 2; i++) printf("-");
    printf("\n");

    int res[201] = { 0 };
    int lines = 0;

    for (int i = 0; i < len2; i++) {
        int d2 = hex_to_int(num2[len2 - 1 - i]);
        if (d2 == 0) {
            printf("%*s0\n", len2 - i + 2, "");
            lines++;
            continue;
        }

        int temp[101] = { 0 }, mul = 0;

        for (int j = 0; j < len1; j++) {
            int d1 = hex_to_int(num1[len1 - 1 - j]);
            int prod = d1 * d2 + mul;
            temp[j] = prod % 16;
            mul = prod / 16;
        }

        if (mul) temp[len1] = mul;

        printf("%*s", len2 - i + 2, "");
        int temp_len = len1 + (mul ? 1 : 0);
        for (int k = temp_len - 1; k >= 0; k--) {
            printf("%c", int_to_hex(temp[k]));
        }
        printf("\n");
        lines++;

        for (int j = 0; j < temp_len; j++) {
            int ind = i + j;
            int val = res[ind] + temp[j];
            res[ind] = val % 16;

            int new_carry = val / 16;
            if (new_carry) {
                int idx = ind + 1;
                while (new_carry) {
                    if (idx >= 200) break;
                    res[idx] += new_carry;
                    new_carry = res[idx] / 16;
                    res[idx] %= 16;
                    idx++;
                }
            }
        }
    }

    if (lines > 1) {
        printf("  ");
        for (int i = 0; i < total_len + 2; i++) printf("-");
        printf("\n  ");
    }

    int res_len = 200;
    while (res_len > 0 && res[res_len] == 0) res_len--;

    for (int i = res_len; i >= 0; i--) {
        printf("%c", int_to_hex(res[i]));
    }
    printf("\n");

    return 0;
}