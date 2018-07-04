#include <stdio.h>
#define SIZE 10

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
    int nums[SIZE] = {0,0,1,1,1,2,2,3,3,4};
    int testCnt, testSize;

    testSize = removeDuplicates(nums, SIZE);
    printf("Remove duplicates length|%d\n", testSize);

    for (testCnt = 0; testCnt < SIZE; testCnt++)
    {
        printf("%d.", nums[testCnt]);
    }
    printf("\n");
    getchar();
    return 0;
}
