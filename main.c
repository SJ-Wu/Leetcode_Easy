#include <stdio.h>
#include <math.h>
#include <limits.h>

int reverse(int x)
{
    long output;
    int digits, digiTotal;
    int xCopy = x;

    digiTotal = 0;
    output    = 0;
    while(xCopy != 0)
    {
        xCopy /= 10;
        digiTotal++;
    }

    xCopy = x;
    for (digits = 0; digits < digiTotal; digits++)
    {
        if (output > INT_MAX || output < INT_MIN) return 0;
        output += (xCopy % 10) * pow(10, (digiTotal-1) - digits);
        xCopy /= 10;
    }
    return output;
}

int main(void)
{
    int inputNum = 123;
    int outputNum;

    printf("Reverse Integer|%d\n", reverse(inputNum));
    getchar();
    return 0;
}
