
#include <stdio.h>

void Two_Sum (int nums[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                printf("[%d,%d]\n",i,j);
                return;
            }
        }
    }
}
int main()
{
    int nums[] = {2,7,11,15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);
    Two_Sum(nums, target, size);
    return 0;
}
