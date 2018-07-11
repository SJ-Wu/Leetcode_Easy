#include <stdio.h>
#include <stdlib.h>

int trailingZeroes(int n)
{
    int cntFive;
    int numTemp;

    cntFive = 0;

    for (n; n > 0; n--)
    {
        numTemp = n;
        while(numTemp % 5 == 0)
        {
            cntFive++;
            numTemp /= 5;
        }
    }
    return cntFive;
}

int main(void)
{
    int zeroes;
    zeroes = trailingZeroes(1808548329);
    printf("Trailing zeroes|%d\n", zeroes);
    getchar();
    return 0;
}
