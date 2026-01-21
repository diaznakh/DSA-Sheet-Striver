#include <vector>
#include <iostream>
#include <algorithm> // Required for std::erase in C++20

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 30, 50};
    int value_to_remove = 30;

    // Use std::erase (C++20)
    erase(vec, value_to_remove);

    // Print the modified vector
    for (int i : vec) {
        cout << i << " "; // Output: 10 20 40 50
    }
    cout << endl;

    return 0;
}
