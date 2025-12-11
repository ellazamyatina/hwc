#include "replaceByMin.h"
#include <string.h>

void sortDigits(char* s)
{
    int n = (int)strlen(s);
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (s[j] > s[j + 1]) {
                char t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
}
void makeMinNumber(char* s)
{
    sortDigits(s);

    if (s[0] == '0') {
        int n = (int)strlen(s);
        for (int i = 1; i < n; ++i) {
            if (s[i] != '0') {
                char t = s[0];
                s[0] = s[i];
                s[i] = t;
                break;
            }
        }
    }
}