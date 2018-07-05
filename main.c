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

    for(numTarget = 1; numTarget <= numsSize; numTarget++)
    {
        for(numCnt = 0; numCnt < numsSize; numCnt++)
        {
            if (numTarget == nums[numCnt])
            {
                break;
            }
        }
        if (numCnt == numsSize)
        {
            printf("Target|%d.%d\n", numTarget, *returnSize);
            disappearNum[disaCnt] = numTarget;
            disaCnt++;
        }
    }
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
    for(int testCnt = 0; testCnt < 2; testCnt++)
    {
        printf("%d.", output[testCnt]);
    }
    printf("\n");
    getchar();
    return 0;
}
