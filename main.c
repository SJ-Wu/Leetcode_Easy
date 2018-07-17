#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int iCnt, iSingle, numTemp, flag;
    for (iSingle = 0; iSingle < numsSize; iSingle++)
    {
        for (iCnt = iSingle + 1; iCnt < numsSize; iCnt++)
        {
            printf("Cmp|%d.%d\n", nums[iSingle], nums[iCnt]);
            if (nums[iSingle] == nums[iCnt])
            {
                numTemp       = nums[iCnt];
                nums[iCnt]    = nums[iSingle + 1];
                nums[iSingle + 1] = numTemp;
                iSingle++;
                break;
            }
        }
        if (iCnt == numsSize) return nums[iSingle];
    }
}
int main(void)
{
    int single;
    int nums[3] = {2,2,1};
    single = singleNumber(nums, 3);
    printf("Single number is %d\n", single);
    getchar();
    return 0;
}
