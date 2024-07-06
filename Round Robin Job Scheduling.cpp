#include<iostream> 
using namespace std; 

void calculateWaitingTime(int task[], int num, int burstTime[], int waitTime[], int timeSlice) 
{ 
    int remainingBurstTime[num]; 
    for (int i = 0 ; i < num ; i++) 
        remainingBurstTime[i] = burstTime[i]; 

    int currentTime = 0; // Current time 

    while (1) 
    { 
        bool done = true;  

        for (int i = 0 ; i < num; i++) 
        { 
            if (remainingBurstTime[i] > 0) 
            { 
                done = false; // There is a pending process 

                if (remainingBurstTime[i] > timeSlice) 
                { 
                    currentTime += timeSlice; 
                    remainingBurstTime[i] -= timeSlice; 
                } 
                else
                { 
                    currentTime = currentTime + remainingBurstTime[i]; 
                    waitTime[i] = currentTime - burstTime[i];  
                    remainingBurstTime[i] = 0; 
                } 
            } 
        } 

        if (done == true) 
            break; 
    } 
} 

void calculateTurnAroundTime(int task[], int num, int burstTime[], int waitTime[], int turnAroundTime[]) 
{  
    for (int i = 0; i < num ; i++) 
        turnAroundTime[i] = burstTime[i] + waitTime[i]; 
} 

void calculateAvgTime(int task[], int num, int burstTime[], int timeSlice) 
{ 
    int waitTime[num], turnAroundTime[num], totalWaitTime = 0, totalTurnAroundTime = 0; 

    calculateWaitingTime(task, num, burstTime, waitTime, timeSlice); 

    calculateTurnAroundTime(task, num, burstTime, waitTime, turnAroundTime); 

    cout << "Tasks "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 

    for (int i=0; i<num; i++) 
    { 
        totalWaitTime = totalWaitTime + waitTime[i]; 
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i]; 
        cout << " " << i+1 << "\t\t" << burstTime[i] <<"\t "
             << waitTime[i] <<"\t\t " << turnAroundTime[i] <<endl; 
    } 
    cout << "Average waiting time = "
         << (float)totalWaitTime / (float)num; 
    cout << "\nAverage turn around time = "
         << (float)totalTurnAroundTime / (float)num; 
} 

int main() 
{  
    int task[] = { 4, 5, 6}; 
    int num = sizeof task / sizeof task[0]; 
    int burst_time[] = {15, 10, 12}; 
    int timeSlice = 3; 
    calculateAvgTime(task, num, burst_time, timeSlice); 
    cout<<endl;    
    return 0;  
}  
