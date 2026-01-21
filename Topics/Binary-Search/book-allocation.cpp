class Solution {
public:
    bool allocationispossible(int barrier, vector<int> &arr, int k) {
        int student = 1;
        int pages = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > barrier) return false;
            
            if (pages + arr[i] > barrier) {
                student++;
                pages = arr[i];  // start counting pages for new student
            } else {
                pages += arr[i];
            }
        }
        
        if (student > k) {
            return false;
        } 
        
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) {
            return -1;  // Not enough books for students
        }
        
        int minarr = *min_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int low = minarr, high = sum;
        int res = -1;

        

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (allocationispossible(mid, arr, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};