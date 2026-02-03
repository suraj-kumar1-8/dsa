#include<iostream>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ans.push_back(1);
                continue;
            }
            if(nums[i]<nums[i-1]){
                ans.push_back(0);
                continue;
            }
            if(nums[i]==nums[i-1]){
                return false;
            }
        }
        if(ans.size()==0 || ans.size()==1){
            return false;
        }
        if(ans[0]==0){
            return false;
        }
        int inc=0;
        int dec=0;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==1 && ans[i+1]==0){
                dec++;
                continue;
            }
            if(ans[i]==0&& ans[i+1]==1){
                inc++;
            }
        }
        if( inc==1 && dec==1){
            return true;
        }
        else{
            return false;
        }
        // return false;

    }
};
int main(){
    Solution s;
    vector<int>nums={1,3,2};
    cout<<s.isTrionic(nums);
    return 0;
}