#include<bits/stdc++.h>
using namespace std;

int main() {
    // Static definition of processes
    int n = 3;
    vector<int> pid  = {1,   2,  3};
    vector<int> ar   = {0,   1,  2};   // arrival times
    vector<int> bt   = {9,   4,  9};   // burst times

    vector<int> ct(n), ta(n), wt(n);
    float total_wt = 0.0f, total_ta = 0.0f;

    int current_time = 0;
    for (int i = 0; i < n; ++i) {
        // if CPU idle, jump to arrival
        current_time = max(current_time, ar[i]);
        ct[i] = current_time + bt[i];
        current_time = ct[i];

        ta[i] = ct[i] - ar[i];
        wt[i] = ta[i] - bt[i];

        total_ta += ta[i];
        total_wt += wt[i];
    }

    // Output results
    cout << "\nPID  Arrival  Burst  Complete  Turnaround  Waiting\n";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << pid[i]
             << setw(8) << ar[i]
             << setw(7) << bt[i]
             << setw(10) << ct[i]
             << setw(12) << ta[i]
             << setw(9) << wt[i]
             << "\n";
    }

    cout << fixed << setprecision(7);
    cout << "\nAverage waiting time:    " << (total_wt / n) << "\n";
    cout << "Average turnaround time: " << (total_ta / n) << "\n";

    return 0;
}
