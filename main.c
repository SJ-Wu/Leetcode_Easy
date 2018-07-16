#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int cntM, cntN, cntL;
    int numTemp;
    for (cntN = 0; cntN < n; cntN++)
    {
        for (cntM = 0; cntM < (m + cntN) ; cntM++)
        {
            if (nums2[cntN] < nums1[cntM])
            {
                numTemp     = nums2[cntN];
                nums2[cntN] = nums1[cntM];
                nums1[cntM] = numTemp;
            }
        }
        nums1[cntM] = nums2[cntN];
    }
}

int main(void)
{
    int nums1[9] = {-1,0,0,3,3,3,0,0,0};
    int nums2[3] = {1,2,2};
    merge(nums1, 6, nums2, 3);
    for (int i = 0; i < 9; i++)
    {
        printf("%d.", nums1[i]);
    }
    getchar();
    return 0;
}
