#include <stdio.h>

void Two_Sum (int nums[], int target, int size) //size = 4 , nums = {2,7,11,15} , target = 26
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
    int target = 26;
    // 4 elements × 4 bytes = 16 bytes
    // nums[0] is just the first integer which mean 2
    // sizeof(nums)   // 16
    // sizeof(nums[0])   // 4
    int size = sizeof(nums) / sizeof(nums[0]); // 16 / 4 = 4
    Two_Sum(nums, target, size);
    return 0;
}
