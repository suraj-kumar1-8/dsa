#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        if(find(result.begin(),result.end(),temp)==result.end()){
                            result.push_back(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    vector<vector<int>> triplets = obj.threeSum(nums);
    
    for (const auto& triplet : triplets) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}