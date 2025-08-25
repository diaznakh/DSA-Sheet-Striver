//for linear search with quadratic time complexity

// class Solution {
// public:
//     bool canWePlace(vector<int> &arr, int dist, int k) {
//         int cntCows = 1;          // Place the first cow
//         int last = arr[0];        // Last position where a cow was placed
//         int n = arr.size();

//         for (int i = 1; i < n; i++) {
//             if (arr[i] - last >= dist) {
//                 cntCows++;
//                 last = arr[i];
//             }
//         }

//         return cntCows >= k;
//     }

//     int aggressiveCows(vector<int> &stalls, int k) {
//         sort(stalls.begin(), stalls.end());

//         int minDist = 1;
//         int maxDist = stalls.back() - stalls.front();

//         int res = 1;  // at least 1 unit distance is always possible

//         for (int i = 1; i <= maxDist; i++) {
//             if (canWePlace(stalls, i, k)) {
//                 res = i;  // update result to the current possible distance
//             } else {
//                 return res;  // i is too much, so return last valid one
//             }
//         }

//         return res;  // all distances worked up to maxDist
//     }
// };


//more optimized solution using binary search

class Solution {
public:
    bool canWePlace(vector<int> &arr, int dist, int k) {
        int cntCows = 1;          // Place the first cow
        int last = arr[0];        // Last position where a cow was placed

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                cntCows++;
                last = arr[i];
            }
        }

        return cntCows >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int low = 1;  // Minimum possible distance
        int high = stalls.back() - stalls.front();  // Max possible distance
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canWePlace(stalls, mid, k)) {
                res = mid;         // Valid placement, try for more
                low = mid + 1;
            } else {
                high = mid - 1;    // Too far apart, reduce distance
            }
        }

        return res;
    }
};