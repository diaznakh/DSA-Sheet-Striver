class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        vector<int> arr1;
        int i = 0, j = 0;
        int n1 = a.size();
        int n2 = b.size();

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                arr1.push_back(a[i]);
                i++;
            } else{
                arr1.push_back(b[j]);
                j++;
            }
        }

        while (i < n1) {
            arr1.push_back(a[i]);
            i++;
        }

        while (j < n2) {
            arr1.push_back(b[j]);
            j++;
        }
        return arr1[k-1];
        
    }
};