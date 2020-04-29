#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

int main()
{
    int pos_1 = 0, pos_2 = 0;
    char* str1, * str2;
    str1 = new char[30];
    str2 = new char[30] ;
    
    cout << "Enter first word: ";
    cin >> str1;
    cout << "Enter second word: ";
    cin >> str2;
    cout << "Enter position 1: ";
    cin >> pos_1;
    cout << "Enter position 2: ";
    cin >> pos_2;
    HMODULE hlib = LoadLibrary(TEXT("Dll1.dll"));//загружаем библиотеку
    if (hlib == NULL) cout << "ERROR_1" << endl;

    typedef void (*function)(char *str1, char *str2, int pos_1, int pos_2);
    function func = (function)GetProcAddress(hlib, "func");
    if (func == NULL) cout << "ERROR_2" << endl;
    else  func(str1, str2, pos_1, pos_2);
        
    FreeLibrary(hlib);//выгружаем 
    system("pause");
}
