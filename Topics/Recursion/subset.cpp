#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find all subset sums
void subsetSumsHelper(const vector<int>& arr, int idx, int currSum, vector<int>& result) {
    if (idx == arr.size()) {
        result.push_back(currSum);
        return;
    }
    // Include current element
    subsetSumsHelper(arr, idx + 1, currSum + arr[idx], result);
    // Exclude current element
    subsetSumsHelper(arr, idx + 1, currSum, result);
}

vector<int> subsetSums(const vector<int>& arr) {
    vector<int> result;
    subsetSumsHelper(arr, 0, 0, result);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> sums = subsetSums(arr);
    cout << "Subset sums: ";
    for (int sum : sums) cout << sum << " ";
    cout << endl;
    return 0;
}