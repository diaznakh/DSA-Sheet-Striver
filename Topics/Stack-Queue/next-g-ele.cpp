#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr;

    int n;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s;
    
    // Start from the end and keep track of greater elements
    for(int i = n-1; i >= 0; i--)
    {
        // Pop elements from stack that are smaller than current element
        while(!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        
        // If stack is not empty, top element is the next greater element
        if(!s.empty())
        {
            result[i] = s.top();
        }
        
        // Push current element to stack
        s.push(arr[i]);
    }
    
    // Print the result
    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

return 0;
}