#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle; 
        for (int row = 0; row < numRows; row++) {
            triangle.push_back(vector<int>(row + 1, 1)); 

            for (int col = 1; col < row; col++) {
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }
        return triangle;
    }
};
int main() {
    int numRows = 5;
    Solution obj;   
    vector<vector<int>> res = obj.generate(numRows);
    for (const auto& row : res) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
