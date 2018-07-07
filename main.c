#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                ".---","-.-",".-..","--","-.","---",".--.","--.-",
                ".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char letters[26] = {"abcdefghijklmnopqrstuvwxyz"};
int uniqueMorseRepresentations(char** words, int wordsSize)
{
    int wordsCnt, lettersCnt, cmpCnt, uniqueCnt, cmpFlag, returnCnt;
    char words2Morse[100][48];

    if (wordsSize == 0) return 0;
    for(wordsCnt = 0; wordsCnt < wordsSize; wordsCnt++)
    {
        for (lettersCnt = 0; words[wordsCnt][lettersCnt] != '\0'; lettersCnt++)
        {
            for (cmpCnt = 0; cmpCnt < 26; cmpCnt++)
            {
                if (words[wordsCnt][lettersCnt] == letters[cmpCnt])
                {
                    strcat(words2Morse[wordsCnt], morse[cmpCnt]);
                    break;
                }
            }
        }
        //printf("w.m|%s->%s\n", words[wordsCnt], words2Morse[wordsCnt]);
    }

    for(wordsCnt = 0; wordsCnt < wordsSize - 1; wordsCnt++)
    {
        for (uniqueCnt = wordsCnt + 1; uniqueCnt < wordsSize; uniqueCnt++)
        {
            //printf("%d->%s\n", wordsCnt, words2Morse[wordsCnt]);
            if (words2Morse[wordsCnt][0] != '\0')
            {
                cmpFlag = strcmp(words2Morse[wordsCnt], words2Morse[uniqueCnt]);
                if (cmpFlag == 0)
                {
                    words2Morse[uniqueCnt][0] = '\0';
                }
            }
        }
    }
    for(wordsCnt = 0, returnCnt = 0; wordsCnt < wordsSize; wordsCnt++)
    {
        if (words2Morse[wordsCnt][0] != '\0') returnCnt++;
    }
    return returnCnt;
}

int removeDuplicates(int* nums, int numsSize)
{
    int numCnt, onlyCnt;
    for (numCnt = 1, onlyCnt = 1; numCnt < numsSize; numCnt++)
    {
        if (nums[numCnt] != nums[numCnt-1])
        {
            nums[onlyCnt++] = nums[numCnt];
        }
    }
    return onlyCnt;
}

int main(void)
{
    int uniqueCnt;
    char* words[5] = {"zocd","gjkl","hzqk","hzgq","gjkl"};
    uniqueCnt = uniqueMorseRepresentations(words, 5);
    printf("Unique|%d\n", uniqueCnt);
    getchar();
    return 0;
}
