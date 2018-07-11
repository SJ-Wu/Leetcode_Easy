#include <stdio.h>
#include <stdlib.h>

int trailingZeroes(int n)
{
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}

int main(void)
{
    int zeroes;
    zeroes = trailingZeroes(1808548329);
    printf("Trailing zeroes|%d\n", zeroes);
    getchar();
    return 0;
}
