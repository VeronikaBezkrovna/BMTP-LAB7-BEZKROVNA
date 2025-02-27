#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

void vowels_removal(wchar_t *str){
    wchar_t str_result[200] = L"";
    int n = 0;
    for (int i = 0; str[i] != L'\0'; i++){
        if(wcschr(L"аАуУеЕоОиИіІяЯїЇєЄюЮaAeEiIoOuU", str[i]) == NULL){
            str_result[n++]=str[i];
        }
    }
    str_result[n]=L'\0';
    wcscpy(str, str_result);
}

int main(void){
    setlocale(LC_ALL, "uk_UA.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);


    wprintf(L"┌─────────────────────────────────────────────────────────────────────────────┐\n");
    wprintf(L"│Програма призначена для розрахунку кількості символів 'й' у введеному реченні│\n");
    wprintf(L"│Безкровна Вероніка Володимирівна                                             │\n");
    wprintf(L"│Контактні дані:                                                              │\n│nika08022007@gmail.com                                                       │\n│+380505876512                                                                │\n");
    wprintf(L"└─────────────────────────────────────────────────────────────────────────────┘\n");

    wchar_t str[200];
    wprintf(L"Введіть речення:\n");
    fgetws(str, 200, stdin);
    size_t lenght=wcslen(str);
    if(lenght>0 && (str[lenght - 1] == L'\n')){
        str[lenght - 1] = L'\0';
    }
    if(!(wcsstr(str, L"//") || wcschr(str, L'-') || wcschr(str, L';'))){
        wprintf(L"Помилка...");
        return 0;
    }
    int number_of_letters=0;
    for(int i=0; str[i]!= L'\0'; i++){
        if(str[i]== L'й'){
            number_of_letters++;
        }
    }
       if (number_of_letters > 0) {
        wprintf(L"Кількість символів 'й': %d\n", number_of_letters);
    } else {
        vowels_removal(str);
        wprintf(L"Речення без голосних: %ls\n", str);
    }
    return 0;
}
