#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];   // final answer
    int currSum = nums[0];  // current subarray sum

    for(int i = 1; i < nums.size(); i++) {
        // Either extend current subarray OR start new subarray from nums[i]
        currSum = max(nums[i], currSum + nums[i]);

        // Update maximum sum
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum is: " << maxSubArray(nums) << endl;

    return 0;
}
