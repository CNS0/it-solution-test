#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* RemoveChar(char* input)
{
    char* dest = input;
    char* src = input;

    while(*src)
    {
        if (!isdigit(*src)) { src++; continue;  } // Проверяет является ли буквой, если да - пропускаем
        *dest++ = *src++; // Если нет - копируем
    }
    *dest = '\0';
    return input;
}

int main(void)
{
    char stringBuffer[64] = { 0 };
    char *endptr;
    long numBuffer;
    long correctVal = 0;
    long value = 1;
    long remainder;

    printf("Программа показывает числа, что делятся на количество разрядов (знаков) без остатка.\n");
    printf("Введите желаемое количество чисел, не более 9,223,372,036,854,775,807.\n");
    printf("Числа с 8 и более разрядами займут значительное время.\n\n");
    fgets(stringBuffer, 64, stdin); // Ввод данных. Не позволяет ввести число больше long

    RemoveChar(stringBuffer); // Санитизация ввода, избавляется от всего, кроме чисел
    numBuffer = strtol(stringBuffer ,&endptr, 10); // Перевод из char** в long

    while(numBuffer != correctVal){
        long nDigits = floor(log10(labs(value))) + 1; // Определяем количество разрядов
        if (((remainder = value%nDigits) != 0)) {value++; continue;} // Проверяет имеется ли остаток, если да - пропускаем.
        printf("%ld ", value); // Если нет -
        value++;
        correctVal++;
    }
    printf("\nЗавершение работы\n");
    return 0;
}
