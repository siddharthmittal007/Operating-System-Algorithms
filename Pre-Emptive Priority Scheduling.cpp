#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent a process
struct Process {
    int id;           // Process ID
    int burst_time;   // Burst time
    int priority;     // Priority
};

// Function to perform priority preemptive scheduling
void priority_preemptive_scheduling(vector<Process>& processes) {
    int n = processes.size();
    int time = 0;

    while (true) {
        int highest_priority = INT16_MAX;
        int selected_process = -1;

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < n; ++i) {
            if (processes[i].burst_time > 0 && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                selected_process = i;
            }
        }

        // If no process is found, all processes have completed
        if (selected_process == -1)
            break;

        // Run the selected process for one time unit
        cout << "Running process P" << processes[selected_process].id << " at time " << time << endl;
        processes[selected_process].burst_time--;
        time++;

        // Check if the selected process has completed
        if (processes[selected_process].burst_time == 0) {
            cout << "Process P" << processes[selected_process].id << " completed at time " << time << endl;
        }
    }
}

int main() {
    
    vector<Process> processes = {
        {1, 3, 3},
        {2, 6, 2},
        {3, 4, 4},
        {4, 2, 1}
    };

    priority_preemptive_scheduling(processes);
    return 0;
}
