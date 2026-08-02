#include <stdbool.h> // Header for C boolean type (true/false)
#include <stdio.h>   // Header for standard input/output (printf)

/**
 * Predicts if Player 1 can win the game given optimal play by both players.
 * 
 * @param nums     Pointer to the array of integers.
 * @param numsSize Number of elements in the nums array.
 * @return true if Player 1 wins or ties, false otherwise.
 */
bool predictTheWinner(int* nums, int numsSize) {

    

    /* ------------------------------------------------------------------------
     * DP TABLE DECLARATION
     * dp[i][j] stores NetScore(i, j) for subarray from index i to index j.
     * Size: numsSize x numsSize matrix.
     * ------------------------------------------------------------------------
     */
    int dp[numsSize][numsSize];

    /* ------------------------------------------------------------------------
     * BASE CASE POPULATION (Subarrays of length 1)
     * For any range [i, i], only one number exists. The active player picks it.
     * ------------------------------------------------------------------------
     */
    for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i]; // Net score when only nums[i] is left = nums[i]
    }

    /* ------------------------------------------------------------------------
     * BOTTOM-UP DYNAMIC PROGRAMMING
     * Fill the table for lengths = 2, 3, ..., up to numsSize.
     * ------------------------------------------------------------------------
     */
    for (int len = 2; len <= numsSize; len++) { // Loop over sub-array lengths
        for (int i = 0; i <= numsSize - len; i++) { // Starting index 'i'
            
            int j = i + len - 1; // Ending index 'j' based on length

            // Choice 1: Take the left element (nums[i])
            // Math: nums[i] - dp[i + 1][j]
            int pickLeft = nums[i] - dp[i + 1][j];

            // Choice 2: Take the right element (nums[j])
            // Math: nums[j] - dp[i][j - 1]
            int pickRight = nums[j] - dp[i][j - 1];

            // Maximize score: Choose the move that yields a higher net score difference
            if (pickLeft > pickRight) {
                dp[i][j] = pickLeft;
            } else {
                dp[i][j] = pickRight;
            }
        }
    }

    /* ------------------------------------------------------------------------
     * FINAL RESULT
     * dp[0][numsSize - 1] holds the net score difference for the entire array.
     * If dp[0][numsSize - 1] >= 0, Player 1 scored at least as much as Player 2.
     * ------------------------------------------------------------------------
     */
    return dp[0][numsSize - 1] >= 0;
}

/* ============================================================================
 * SIMPLE MAIN FUNCTION FOR TESTING
 * ============================================================================
 */
int main() {
    // Test Case 1: [1, 5, 2] -> Expected output: False (0)
    int nums1[] = {1, 5, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1 [1, 5, 2]: %s\n", 
            predictTheWinner(nums1, size1) ? "True" : "False");

    // Test Case 2: [1, 5, 233, 7] -> Expected output: True (1)
    int nums2[] = {1, 5, 233, 7};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2 [1, 5, 233, 7]: %s\n", 
            predictTheWinner(nums2, size2) ? "True" : "False");

    return 0;
}