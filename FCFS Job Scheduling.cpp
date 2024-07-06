#include <iostream>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void sort(Process process[],int numProcesses)
{
    for(int i=0;i<numProcesses-1;i++)
    {
        for(int j=0;j<numProcesses-1-i;j++)
        {
            if(process[j].arrivalTime>process[j+1].arrivalTime)
            {
                Process temp=process[j+1];
                process[j+1]=process[j];
                process[j]=temp;
            }
        }
    }
}
void calculateTimes(Process process[], int numProcesses)
{
    int currentTime = 0;

    for (int i=0; i<numProcesses; i++)
    {
        if (process[i].arrivalTime > currentTime)
            currentTime = process[i].arrivalTime;

        process[i].waitingTime = currentTime - process[i].arrivalTime;
        process[i].turnaroundTime = process[i].waitingTime + process[i].burstTime;
        currentTime += process[i].burstTime;
        process[i].completionTime=currentTime;
    }
}

int main()
{
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    cout<<endl;

    Process process[numProcesses];

    for (int i = 0; i < numProcesses; i++)
    {
        process[i].id = i + 1;
        cout << "\nEnter arrival time for Process " << i + 1 << ": ";
        cin >> process[i].arrivalTime;
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> process[i].burstTime;
    }

    sort(process, numProcesses);

    calculateTimes(process, numProcesses);

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numProcesses; ++i)
    {
        for(int j=0;j<numProcesses;++j)
        {
            if(process[j].id==i+1)
            {
                cout << process[j].id << "\t" << process[j].arrivalTime << "\t\t"
             << process[j].burstTime << "\t\t" << process[j].completionTime<<"\t\t"<< process[j].waitingTime << "\t\t"
             << process[j].turnaroundTime << endl;
            }
        }

    }

    return 0;
}
