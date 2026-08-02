#include <stdio.h>
#include <stdbool.h>

bool predictTheWinner(int* nums, int numsSize)
{
    printf("%d\n", numsSize);
    printf("%d\n", nums[2]);
    return true;
}

int main(void)
{
    int nums[] = {1, 5, 2};
    predictTheWinner(nums, 3);
    return 0;
}