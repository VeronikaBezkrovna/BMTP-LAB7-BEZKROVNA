#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int main(void){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ukrainian");

    wprintf(L"┌─────────────────────────────────────────────────────────────────────────────────────────┐\n");
    wprintf(L"│Програма призначена для розрахунку кількості та суми додатних елементів введеного масиву.│\n");
    wprintf(L"│Безкровна Вероніка Володимирівна                                                         │\n");
    wprintf(L"│Контактні дані:                                                                          │\n│nika08022007@gmail.com                                                                   │\n│+380505876512                                                                            │\n");
    wprintf(L"└─────────────────────────────────────────────────────────────────────────────────────────┘\n");

    wprintf(L"Введіть елементи масиву:\n");
    float sum=0, arr[14];
    int number=0;
    char check=0;
    for(int i=0; i<14; i++){
        scanf("%f", &arr[i]);
        check = wscanf(L"%f", &arr[i]);
        if (check!=1){
            getchar();
            wprintf(L"\nПомилка...");
            return 0;
        }
    }
    for(int i=0; i<14; i++){
        if (arr[i]>0){
            number++;
            sum=arr[i]+sum;
        }
    }
    wprintf(L"Кількість додатніх елементів: %d\n", number);
    wprintf(L"Сума додатніх елементів: %.3f\n", sum);
    return 0;
}
