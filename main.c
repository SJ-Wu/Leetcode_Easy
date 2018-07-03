#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int numCnt;
    for (numCnt = 0; numCnt < numsSize; numCnt++)
    {
        if (target == nums[numCnt])
        {
            return numCnt;
        }
        else if (target < nums[numCnt])
        {
            return numCnt;
        }
    }
    return numCnt;
}

int main(void)
{
    int array[4] = {1, 3, 5, 6};
    int targetNum = 0;

    printf("Insert position|%d\n", searchInsert(array, 4, targetNum));
    getchar();
    return 0;
}
