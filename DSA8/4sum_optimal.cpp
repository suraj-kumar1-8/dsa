#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 4)
      return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n - 2; ++j)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int p = j + 1;
        int q = n - 1;
        while (p < q)
        {
          long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];
          if (sum == target)
          {
            ans.push_back({nums[i], nums[j], nums[p], nums[q]});
            ++p;
            --q;
            while (p < q && nums[p] == nums[p - 1])
              ++p;
            while (p < q && nums[q] == nums[q + 1])
              --q;
          }
          else if (sum < target)
          {
            ++p;
            while (p < q && nums[p] == nums[p - 1])
              ++p;
          }
          else
          {
            --q;
            while (p < q && nums[q] == nums[q + 1])
              --q;
          }
        }
      }
    }
    return ans;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  if (!(cin >> n))
    return 0;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  int target;
  cin >> target;

  Solution sol;
  auto res = sol.fourSum(nums, target);
  for (auto &v : res)
  {
    for (size_t i = 0; i < v.size(); ++i)
    {
      if (i)
        cout << ' ';
      cout << v[i];
    }
    cout << '\n';
  }
  return 0;
}
