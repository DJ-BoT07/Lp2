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

void jobScheduling(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> slot(n, -1);
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
    cout << "Scheduled Jobs in order: "<< endl;
    for (int i = 0; i < n; i++) {
        if (slot[i] != -1) {
            cout << " Slot : "<< slot[i] << " " << endl;
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {
        {1, 5, 100},  // Job 1: Deadline 5, Profit 100
        {2, 7, 50},   // Job 2: Deadline 4, Profit 50
        {3, 3, 75},   // Job 3: Deadline 3, Profit 75
        {4, 2, 60},   // Job 4: Deadline 2, Profit 60
        {5, 1, 40}    // Job 5: Deadline 1, Profit 40
    };
    int n = jobs.size();

    jobScheduling(jobs, n);

    return 0;
}
