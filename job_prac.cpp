#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3;
    vector<int> pid = {1,2,3};
    vector<int> ar = {0,1,2};
    vector<int> bt = {9,4,9};

    vector<int> ct(n),ta(n), wt(n);
    float total_wt= 0.0f, total_ta = 0.0f;

    for(int i = 0;  i < n;i++){
        if(i == 0 || ar[i] > ct[i - 1]){
            ct[i] = ar[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }

        ta[i] = ct[i] - ar[i];
        wt[i] = ta[i] - bt[i];

        total_wt += wt[i];
        total_ta = ta[i];
    }

     cout << "\nPID  Arrival  Burst  Complete  Turnaround  Waiting\n";
     for(int i = 0;i <n;i++){
        cout << setw(3) << pid[i]
             << setw(8) << ar[i]
             << setw(7) << bt[i]
             << setw(10) << ct[i]
             << setw(12) << ta[i]
             << setw(9) << wt[i]
             << "\n";
     }
    cout << "\nAverage waiting time:    " << (total_wt / n) << "\n";
    cout << "Average turnaround time: " << (total_ta / n) << "\n";

    return 0;
}