#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

// Comparator to sort items by value/weight ratio in descending order
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    int currWeight = 0;

    for (int &item : items) {
        if (currWeight + item.weight <= W) {
            currWeight += item.weight;
            totalValue += item.value;
        } else {
            int remain = W - currWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items1 = {{60, 10}, {100, 20}, {120, 30}};
    int W1 = 50;
    cout << "Test 1 - Maximum value in Knapsack = " << fractionalKnapsack(W1, items1) << endl;

    vector<Item> items2 = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};
    int W2 = 15;
    cout << "Test 2 - Maximum value in Knapsack = " << fractionalKnapsack(W2, items2) << endl;

    vector<Item> items3 = {{20, 5}, {30, 10}, {40, 15}};
    int W3 = 20;
    cout << "Test 3 - Maximum value in Knapsack = " << fractionalKnapsack(W3, items3) << endl;

    return 0;
}