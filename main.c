#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>   

#define LOGIN    "admin"
#define PASSWORD "1234"
#define MAX_ATTEMPTS 3

int rgz();
int rec();


int authorize() {
    char inputLogin[50];
    char inputPass[50];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Введите логин: ");
        scanf("%49s", inputLogin);
        printf("Введите пароль: ");
        scanf("%49s", inputPass);

        if (strcmp(inputLogin, LOGIN) == 0 && strcmp(inputPass, PASSWORD) == 0) {
            printf("Авторизация успешна!\n\n");
            return 1;
        } else {
            attempts++;
            printf("Неверный логин или пароль. Осталось попыток: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    printf("Превышено количество попыток. Доступ запрещён.\n");
    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");

    if (!authorize()) {
        return 1;  
    }

    int choice;
    do {
        printf("1. РГЗ\n");
        printf("2. Рекурсия\n");
        printf("0. Выход\n");
        printf("Выберите проект: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nРГЗ\n");
            rgz();
            break;
        case 2:
            printf("\nРекурсия\n");
            rec();
            break;
        case 0:
            printf("Выход\n");
            break;
        default:
            printf("Неверное значение\n");
        }
    } while (choice != 0);

    return 0;
}
