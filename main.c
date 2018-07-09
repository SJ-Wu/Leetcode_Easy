#include <stdio.h>
#include <stdlib.h>

int min(int num1, int num2)
{
    if (num1 > num2)
    {
        return num2;
    }
    else if (num1 < num2)
    {
        return num1;
    }
    return num1;
}

void find2and5(int num, int* cntTwo, int* cntFive)
{
    int numTemp = num;
    int cnt2, cnt5;

    cnt2 = *cntTwo;
    cnt5 = *cntFive;

    while(numTemp % 2 == 0)
    {
        cnt2++;
        numTemp /= 2;
    }

    numTemp = num;
    while(numTemp % 5 == 0)
    {
        cnt5++;
        numTemp /= 5;
    }
    *cntTwo  = cnt2;
    *cntFive = cnt5;
    //printf("%d.%d\n", *cntTwo, *cntFive);
}

int trailingZeroes(int n)
{
    int zeroes  = 0;
    int cntTwo, cntFive;

    cntTwo = cntFive = 0;

    for (n; n > 0; n--)
    {
        find2and5(n, &cntTwo, &cntFive);
    }
    printf("Cnt2.5|%d.%d\n", cntTwo, cntFive);
    zeroes = min(cntTwo, cntFive);
    return zeroes;
}

int main(void)
{
    int zeroes;
    zeroes = trailingZeroes(1808548329);
    printf("Trailing zeroes|%d\n", zeroes);
    getchar();
    return 0;
}
