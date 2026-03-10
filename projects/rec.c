#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define N 1024

// Функция рекурсивной проверки баланса скобок
bool checkBracketBalance(char* s, int* i, char arg_close) {
    while (s[*i] && s[*i] != ')' && s[*i] != ']' && s[*i] != '}') {
        if (isalpha(s[*i])) {
            (*i)++; // буквы пропускаем
        } else {
            char close; // ИСПРАВЛЕНО: было char close = ""; (некорректная инициализация)
            switch (s[*i]) {
            case '(':
                close = ')';
                // проверка на пустые скобки ()
                if (s[++(*i)] == close && s[*i - 1] == '(') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            case '[':
                close = ']';
                // проверка на пустые скобки []
                if (s[++(*i)] == close && s[*i - 1] == '[') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            case '{':
                close = '}';
                // проверка на пустые скобки {}
                if (s[++(*i)] == close && s[*i - 1] == '{') return false;
                if (!checkBracketBalance(s, i, close)) return false;
                if (s[*i] != close) return false;
                (*i)++;
                break;

            default:
                return false; // недопустимый символ
            }
        }
    }
    // Проверяем, что закрывающая скобка соответствует ожидаемой
    if (arg_close != 0 && s[*i] != arg_close) return false;
    return true;
}

// ИСПРАВЛЕНО: переименовали rec в main (или можно было оставить rec и добавить main)
int main() {
    setlocale(LC_ALL, "ru");
    char s[N];
    fgets(s, N, stdin);                // ИСПРАВЛЕНО: убрали sizeof(char) – он равен 1
    s[strcspn(s, "\n")] = '\0';        // удаляем перевод строки
    int i = 0;
    // ИСПРАВЛЕНО: передаём s, а не &s
    printf("result: %d", checkBracketBalance(s, &i, 0) && s[i] == '\0');
    return 0;
}
