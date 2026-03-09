#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int rgz();
int rec();

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;
    do
    {
        printf("1. РГЗ\n");
        printf("2. Рекурсия\n");
        printf("0. Выход\n");
        printf("Выберите проект: ");
        scanf("%d", &choice);
        switch (choice)
        {
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