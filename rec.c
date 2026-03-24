#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define N 1024


bool checkBracketBalance(char* s, int* i, char arg_close) {
    while (s[*i] && s[*i] != ')' && s[*i] != ']' && s[*i] != '}') {
        if (isalpha(s[*i])) (*i)++;
        else {
            char close = "";
            switch (s[*i]) {
            case '(':
                close = ')';
                if (s[++(*i)] == ')' && s[*i - 1] == '(') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            case '[':
                close = ']';
                if (s[++(*i)] == ']' && s[*i - 1] == '[') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            case '{':
                close = '}';
                if (s[++(*i)] == '}' && s[*i - 1] == '{') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            default: return false;
            }
        }
    }
    if (arg_close != 0 && s[*i] != arg_close) return false;
    return true;
}

int rec() {
    setlocale(LC_ALL, "ru");
    char s[N];
    fgets(s, N * sizeof(char), stdin);
    s[strcspn(s, "\n")] = '\0';
    int i = 0;
    printf("result: %d", checkBracketBalance(&s, &i, 0) && s[i] == '\0');

    return 0;
}
