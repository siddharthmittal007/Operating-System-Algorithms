#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a process
struct Process 
{
    int id;           // Process ID
    int burst_time;   // Burst time
    int priority;     // Priority
};




// Function to perform non-preemptive priority scheduling
void non_preemptive_priority_scheduling(vector<Process>& processes) 
{
    int n = processes.size();
    int time = 0;
    
    // Sort processes by priority (lower priority value means higher priority)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });

    for (int i = 0; i < n; i++) 
    {
        cout << "Running process P" << processes[i].id << " from time " << time << " to ";
        time += processes[i].burst_time;
        cout << time << endl;
    }
}

int main() 
{    
     vector<Process> processes = {
        {1, 3, 3},
        {2, 6, 2},
        {3, 4, 4},
        {4, 2, 1}
    };
    non_preemptive_priority_scheduling(processes);
    return 0;
} 
