#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLeaders(vector<int>& arr, int n) {
    vector<int> leaders;

    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(maxFromRight);
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    int n = arr.size();

    vector<int> result = findLeaders(arr, n);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
