#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;        // Job ID
    int deadline;  // Deadline of job
    int profit;    // Profit for completing the job
};

// Sort jobs by profit descending
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    // 1) Find the real maximum deadline
    int maxDead = 0;
    for (auto &j : jobs) 
        maxDead = max(maxDead, j.deadline);

    // 2) Prepare slots for time 1..maxDead
    vector<int> slot(maxDead, -1);
    int totalProfit = 0;

    // 3) Greedily schedule into the latest free slot ≤ deadline
    for (auto &j : jobs) {
        for (int t = j.deadline - 1; t >= 0; --t) {
            if (slot[t] == -1) {
                slot[t] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    // 4) Print real timing
    cout << "Total Profit: " << totalProfit << "\n";
    cout << "Schedule by real time slots:\n";
    for (int t = 0; t < maxDead; ++t) {
        cout << " Time " << (t+1) << ": ";
        if (slot[t] == -1) 
            cout << "(idle)\n";
        else
            cout << "Job " << slot[t] << "\n";
    }
}

int main() {
    vector<Job> jobs = {
        {1, 5, 100},
        {2, 4,  50}
    };
    jobScheduling(jobs);
    return 0;
}
