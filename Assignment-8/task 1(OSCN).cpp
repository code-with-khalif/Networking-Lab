#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    string pid;
    int at, bt;
    int ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> p[i].pid;

        cout << "Arrival Time: ";
        cin >> p[i].at;

        cout << "Burst Time: ";
        cin >> p[i].bt;
    }

    // Sort by arrival time
    sort(p, p + n, [](Process a, Process b){
        return a.at < b.at;
    });

    int current_time = 0;
    int total_tat = 0, total_wt = 0;

    // FCFS Calculation
    for (int i = 0; i < n; i++) {

        // Handle CPU idle time
        if (current_time < p[i].at) {
            current_time = p[i].at;
        }

        p[i].ct = current_time + p[i].bt;
        current_time = p[i].ct;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt  += p[i].wt;
    }

    // Output
    cout << "\n---------------------------------------------";
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT";
    cout << "\n---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t"
             << p[i].at  << "\t"
             << p[i].bt  << "\t"
             << p[i].ct  << "\t"
             << p[i].tat << "\t"
             << p[i].wt  << "\n";
    }

    cout << "---------------------------------------------\n";
    cout << "Total TAT = " << total_tat << endl;
    cout << "Total WT  = " << total_wt  << endl;
    cout << "Average TAT = " << (float)total_tat / n << endl;
    cout << "Average WT  = " << (float)total_wt  / n << endl;

    return 0;
}
