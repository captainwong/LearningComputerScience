#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define NUMBER 3


void rev_swap(char* a, char* b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void rev_str(char s[], int len) {
    for (int i = 0; i < len / 2; i++) {
        rev_swap(&s[i], &s[len - i - 1]);
    }
}

// sn s的第一维长度，如s[2][128]的sn是2
// n 要逆转的字符数量
void rev_string(char s[][128], int sn, int n)
{
    for (int i = 0; i < sn; i++) {
        rev_str(s[i], n);
    }
}
 
int main()
{
    int i;
    char str[NUMBER][128] = {
        "abcdefg", "1234567", "defaaa"
    };
    rev_string(str, NUMBER, 3);
    printf("以下为经过变换后的字符串。\n");
    for (i = 0; i < NUMBER; i++) {
        printf("s[%d] = \"%s\"\n", i, str[i]);
    }

    return 0;
}