
#include "pch.h"
#include "Dll_h.h"
#include <iostream>
#include <string.h>
using namespace std;

void func(char* str1, char* str2, int position_1, int position_2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (position_1 >= len1 || position_1 >= len2 || position_2 >= len1 || position_2 >= len2) {
        cout << "ERROR, enter other position \n";
        return;
    }
    char* res_1, * res_2;
    res_1 = workWithStr(str1, str2, position_1, position_2);
    res_2 = workWithStr(str2, str1, position_2, position_1);
    int lenR_1, lenR_2;
    lenR_1 = strlen(res_1); lenR_2 = strlen(res_2);
    char* result = new char[lenR_1 + lenR_2 + 1];
    for (int i = 0, j = 0; i < lenR_1 + lenR_2; i++) {
        if (i < lenR_1) result[i] = res_1[i];
        else { result[i] = res_2[j]; j++; }
    }
    result[lenR_1 + lenR_2] = '\0';
    cout << result << endl;
}

char* workWithStr(char* str1, char* str2, int position_1, int position_2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* str = new char[position_1 + len2 - position_2 + 1];

    for (int i = 0; i < position_1; i++) {
        str[i] = str1[i];
    }

    for (int i = position_2, j = position_1; i < len2; i++, j++) {
        str[j] = str2[i];
    }

    str[position_1 + len2 - position_2] = '\0';
    return str;
}