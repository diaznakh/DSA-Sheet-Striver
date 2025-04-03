//problem of Minimum Platforms requires a 
//greedy approach to find the minimum number 
//of platforms needed at a railway station so 
//that no train waits.

#include <iostream>
#include <algorithm>
using namespace std;

int findMinPlatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}

int main() {
    // Test case 1
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum number of platforms needed (Test 1): " << findMinPlatforms(arr1, dep1, n1) << endl;

    // Test case 2
    int arr2[] = {900, 945, 955, 1100, 1500, 1800};
    int dep2[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Minimum number of platforms needed (Test 2): " << findMinPlatforms(arr2, dep2, n2) << endl;

    // Test case 3
    int arr3[] = {100, 200, 300, 400};
    int dep3[] = {110, 210, 310, 410};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Minimum number of platforms needed (Test 3): " << findMinPlatforms(arr3, dep3, n3) << endl;

    return 0;
}

//help of copilot