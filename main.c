#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int answer, iSingle;
    answer = 0;
    for (iSingle = 0; iSingle < numsSize; iSingle++)
    {
        answer ^= nums[iSingle];
    }
    return answer;
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
