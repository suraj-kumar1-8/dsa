#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
    int candidate = 0;
    int count = 0;

    for (int x : nums) {
        if (count == 0) {
            candidate = x;   // new candidate
        }

        if (x == candidate) {
            count++;         // same element -> increase count
        } else {
            count--;         // different element -> decrease count
        }
    }

    return candidate; // majority element
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element is: " << majorityElement(nums) << endl;

    return 0;
}
