#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store meeting information
struct Meeting {
    int start;
    int end;
    int pos;
};

// Comparator to sort meetings by end time
bool compare(Meeting m1, Meeting m2) {
    if (m1.end == m2.end)
        return m1.pos < m2.pos;
    return m1.end < m2.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }
    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;
    int last_end = meetings[0].end;
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= last_end) {
            count++;
            last_end = meetings[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] =   {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;
    return 0;
}