#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int  numCnt, numTarget;
    int* disappearNum;
    int disaCnt;
    disappearNum = malloc(sizeof(int) * numsSize);
    disaCnt = 0;

    for(numCnt = 0; numCnt < numsSize; numCnt++)
    {
        disappearNum[numCnt] = numCnt + 1;
        printf("%d.", disappearNum[numCnt]);
    }
    printf("\n");

    for(numCnt = 0; numCnt < numsSize; numCnt++)
    {
        if (nums[numCnt] == disappearNum[nums[numCnt] - 1])
        {
            disappearNum[nums[numCnt] - 1] = 0;
        }
        printf("%d.", disappearNum[numCnt]);
    }
    printf("\n");

    for(numCnt = 0; numCnt < numsSize; numCnt++)
    {
        if(disappearNum[numCnt] != 0)
        {
            disappearNum[disaCnt] = disappearNum[numCnt];
            disaCnt++;
        }
        printf("%d.", disappearNum[numCnt]);
    }
    printf("\n");

    *returnSize = disaCnt;
    return disappearNum;
}

int main(void)
{
    int input[8] = {4,3,2,7,8,2,3,1};
    int* output;
    int returnSize;

    output = findDisappearedNumbers(input, 8, &returnSize);
    printf("Rsize.%d\n", returnSize);
    for(int testCnt = 0; testCnt < returnSize; testCnt++)
    {
        printf("%d.", output[testCnt]);
    }
    printf("\n");
    getchar();
    return 0;
}
