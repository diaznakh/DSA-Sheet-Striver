#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    // Create a slot array to keep track of assigned jobs
    vector<int> slot(maxDeadline + 1, -1); // slot[i] = job id assigned to time i
    int countJobs = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                countJobs++;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }
    return {countJobs, maxProfit};
}

int main() {
    vector<Job> jobs1 = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    auto res1 = jobSequencing(jobs1);
    cout << "Test 1 - Number of jobs done: " << res1.first << ", Maximum profit: " << res1.second << endl;

    vector<Job> jobs2 = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    auto res2 = jobSequencing(jobs2);
    cout << "Test 2 - Number of jobs done: " << res2.first << ", Maximum profit: " << res2.second << endl;

    vector<Job> jobs3 = {
        {1, 1, 10},
        {2, 2, 20},
        {3, 3, 30}
    };
    auto res3 = jobSequencing(jobs3);
    cout << "Test 3 - Number of jobs done: " << res3.first << ", Maximum profit: " << res3.second << endl;

    return 0;
}