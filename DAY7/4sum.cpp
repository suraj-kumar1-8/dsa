#include<iostream>
#include<vector>
using namespace std;
class solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];
                    if (sum == target) {
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while (left < right && arr[left] == arr[left + 1]) left++;
                        while (left < right && arr[right] == arr[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < n && arr[j] == arr[j + 1]) j++;
            }
            while (i + 1 < n && arr[i] == arr[i + 1]) i++;
        }
        return ans;
    }
};
int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    solution obj;
    vector<vector<int>> res = obj.fourSum(arr, target);
    for (const auto& quad : res) {
        for (const auto& num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
