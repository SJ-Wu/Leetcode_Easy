#include <stdio.h>

int strStr(char* haystack, char* needle)
{
    int cntHaystack, cntNeedle;

    if (needle[0] == '\0') return 0;
    for(cntHaystack = 0; haystack[cntHaystack] != '\0'; cntHaystack++)
    {
        for (cntNeedle = 0; needle[cntNeedle] != '\0'; cntNeedle++)
        {
            printf("[%d]%c.[%d]%c\n", cntHaystack + cntNeedle, haystack[cntHaystack + cntNeedle], cntNeedle, needle[cntNeedle]);
            if (haystack[cntHaystack + cntNeedle] != needle[cntNeedle])
            {
                break;
            }
        }
        printf("%d\n", cntNeedle);
        if (needle[cntNeedle] == '\0') return cntHaystack;
    }
    return -1;
}

int main(void)
{
    char* haystack = {"aaa"};
    char* needle   = {"aaaa"};
    int needleIndex;

    needleIndex = strStr(haystack, needle);
    printf("%d\n", needleIndex);
    getchar();
    return 0;
}
