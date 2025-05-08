#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;        // Job ID
    int deadline;  // Deadline of job
    int profit;    // Profit for completing the job
};

// Function to compare jobs based on profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs, int n) {
    // Step 1: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> slot(n, -1);  // Keep track of scheduled jobs
    int totalProfit = 0;

    // Step 2: Assign jobs to time slots
    for (int i = 0; i < n; i++) {
        // Try to schedule this job in a time slot before its deadline
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {  // If the slot is available
                slot[j] = jobs[i].id;  // Schedule the job
                totalProfit += jobs[i].profit;  // Add job's profit to total
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
    vector<Job> jobs = {{1, 5, 100},{2,4,50} };
    int n = jobs.size();

    jobScheduling(jobs, n);  // Call the job scheduling function

    return 0;
}