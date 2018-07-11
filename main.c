#include <stdio.h>

int romanToInt(char* s)
{
    int  iCnt, answer;

    iCnt = answer = 0;
    while(s[iCnt] != '\0')
    {
        switch (s[iCnt])
        {
            case 'I':
                if ((s[iCnt+1] == 'V') || (s[iCnt+1] == 'X'))
                {
                    answer -= 1;
                }
                else
                {
                    answer += 1;
                }
                break;
            case 'V':
                answer += 5;
                break;
            case 'X':
                if ((s[iCnt+1] == 'L') || (s[iCnt+1] == 'C'))
                {
                    answer -= 10;
                }
                else
                {
                    answer += 10;
                }
                break;
            case 'L':
                answer += 50;
                break;
            case 'C':
                if ((s[iCnt+1] == 'D') || (s[iCnt+1] == 'M'))
                {
                    answer -= 100;
                }
                else
                {
                    answer += 100;
                }
                break;
            case 'D':
                answer += 500;
                break;
            case 'M':
                answer += 1000;
                break;
            default:
                break;
        }
        iCnt++;
    }
    return answer;
}

int main(void)
{
    char* roman = {"MCMXCIV"};
    int rom2Int;

    rom2Int = romanToInt(roman);
    printf("%s|%d\n", roman, rom2Int);
    getchar();
    return 0;
}
