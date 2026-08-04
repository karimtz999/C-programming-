#include <stdio.h>

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 26;
    int size = sizeof(nums) / sizeof(nums[0]);
    Two_Sum(nums, target, size);
    freeTable();
    return 0;
}
