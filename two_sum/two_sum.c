
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j;
    returnSize = (int *)malloc(sizeof(int) * 2);
    while (i < numsSize)
    {
        j = i + 1;
        while(j < numsSize)
        {   
            if (nums[i] + nums[j] == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
            j++;
        }
        i++;
    }
    return returnSize;
}

int main() {
    // Example array and target
    int nums[] = {2, 5, 11, 15, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int* result = NULL;
    
    // Calling the twoSum function
    result = twoSum(nums, numsSize, target, result);
    
    // If result is not NULL, print the indices
    if (result) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);  // Don't forget to free the allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}