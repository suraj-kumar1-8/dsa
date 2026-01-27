#include <iostream>
#include <vector>
using namespace std;

class ArrayManipulator {
public:
    vector<int> rearrangeBySign(vector<int>& A) {
        int n = A.size();

        vector<int> ans(n, 0);

        
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++) {
            if (A[i] < 0) {
                ans[negIndex] = A[i];
                negIndex += 2;
            } else {
                ans[posIndex] = A[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> A = {1, 2, -4, -5};

    ArrayManipulator obj;

    vector<int> result = obj.rearrangeBySign(A);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
