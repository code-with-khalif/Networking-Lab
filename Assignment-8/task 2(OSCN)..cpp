#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string pid;
    int at, bt;
    int ct, tat, wt;
    bool completed = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> p[i].pid;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Burst Time: ";
        cin >> p[i].bt;
    }

    int completedCount = 0;
    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    cout << "\nGANTT CHART: \n";
    cout << "--------------------------------------------------\n";

    // SJF Logic (Non-preemptive)
    while (completedCount < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Find process with minimum BT that has arrived & not completed
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && !p[i].completed) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }

        // If no process has arrived, CPU is idle
        if (idx == -1) {
            current_time++;
            continue;
        }

        // Execute selected process
        cout << "[" << current_time << "]--" << p[idx].pid << "--";

        current_time += p[idx].bt;
        p[idx].ct = current_time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].completed = true;

        total_tat += p[idx].tat;
        total_wt += p[idx].wt;
        completedCount++;
    }

    cout << "[" << current_time << "]\n";
    cout << "--------------------------------------------------\n\n";

    // Output Table
    cout << "-------------------------------------------------------------\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-------------------------------------------------------------\n";

    for (auto &pr : p) {
        cout << pr.pid << "\t"
             << pr.at << "\t"
             << pr.bt << "\t"
             << pr.ct << "\t"
             << pr.tat << "\t"
             << pr.wt << "\n";
    }

    cout << "-------------------------------------------------------------\n";
    cout << "Average Turnaround Time = " << (total_tat / n) << endl;
    cout << "Average Waiting Time    = " << (total_wt / n) << endl;

    return 0;
}

