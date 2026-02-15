#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1;   // move left
        }
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1;   // move right
        }
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,2,2,3,4,5};
    int target = 2;

    cout << "First Occurrence: " << firstOccurrence(arr, target) << endl;
    cout << "Last Occurrence: " << lastOccurrence(arr, target) << endl;

    return 0;
}
