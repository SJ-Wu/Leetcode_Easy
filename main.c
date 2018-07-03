#include <stdio.h>
#define SIZE 4

int removeElement(int* nums, int numsSize, int val) {
    int numCnt, removeCnt;
    int testCnt;
    removeCnt = 0;
    for (numCnt = 0; numCnt < (numsSize - removeCnt); numCnt++)
    {
        if (val == nums[numCnt])
        {
            while((val == nums[(numsSize - 1) - removeCnt]) && (removeCnt != numsSize))
            {
                removeCnt++;
            }

            if (numCnt < (numsSize - removeCnt))
            {
                nums[numCnt] = nums[(numsSize - 1) - removeCnt];
                nums[(numsSize - 1) - removeCnt] = val;
                printf("C.R|%d.%d|", numCnt, removeCnt);
                for (testCnt = 0; testCnt < SIZE; testCnt++)
                {
                    printf("%d.", nums[testCnt]);
                }
                printf("\n");
            }
            if (removeCnt == numsSize) break;
        }
    }
    return numsSize - removeCnt;
}

int main(void)
{
    int nums[SIZE] = {3, 2, 2, 3};
    int val = 3;
    int testCnt, testSize;

    testSize = removeElement(nums, SIZE, val);
    printf("Remove element|%d\nTotal length|%d\n", val, testSize);

    for (testCnt = 0; testCnt < SIZE; testCnt++)
    {
        printf("%d.", nums[testCnt]);
    }
    printf("\n");
    getchar();
    return 0;
}
