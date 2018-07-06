#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    char* commonPrefix;
    int strCnt, charCnt, comCnt;

    comCnt = 1;
    while(strs[0][comCnt] != '\0')
    {
        comCnt++;
    }
    commonPrefix = malloc(sizeof(char) * comCnt);

    for (charCnt = 0; strs[0][charCnt] != '\0'; charCnt++)
    {
        for (strCnt = 0; strCnt < (strsSize - 1); strCnt++)
        {
            if (strs[strCnt][charCnt] != strs[strCnt + 1][charCnt])
            {
                commonPrefix[charCnt] = '\0';
                return commonPrefix;
            }
        }
        commonPrefix[charCnt] = strs[0][charCnt];
    }
    commonPrefix[charCnt] = '\0';
    return commonPrefix;
}

int main(void)
{
    char* strings[3] = {"flower","flow","flight"};
    char* commonPrefix;

    commonPrefix = longestCommonPrefix(strings, 3);
    printf("%s\n", commonPrefix);
    getchar();
    return 0;
}
