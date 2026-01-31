// n/3 times
#include<iostream>
#include<vector>
using namespace std;  
class Solution {
public:
    int majorityElement(vector<int>& arr, int n) {
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                }
            }
            if(count > n / 3) {
                return arr[i];
            }
        }
        return -1; // No majority element found
    }
};
int main() {
    vector<int> arr = {3, 2, 3};
    int n = arr.size();
    Solution obj;
    int res = obj.majorityElement(arr, n);
    cout << res << endl;
    return 0;
}