#include <iostream>
#include <vector>

using namespace std;


void findMin(int v){
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;

    vector<int> ans;

    for(int i = n-1; i >= 0; i--){
        while(v >= deno[i]){
            v -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    int fns =0;
    cout << "The denominations are: ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
        fns++;
    }
    cout<< endl;
    cout<<"Minimum number is: "<<fns;
    cout << endl;
}
int main(){
    int value;
    cout << "Enter the amount: ";
    cin >> value;
    findMin(value);
    return 0;
}