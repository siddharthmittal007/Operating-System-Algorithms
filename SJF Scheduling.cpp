#include <iostream>
using namespace std;

int main(){
    //data to store process ID , burst time , 
    //average waiting time , average turn around time
    int data[100][4];
    int n, index;
    float total;
    cout<<"Enter number of process: ";
    cin>>n;

    //input burst time and allocate process id
    cout<<"Enter Burst Time: "<<endl;
    for(int i = 0; i<n ; i++){
        cout<<"P"<<i+1<<": ";
        //take burst time from user
        cin>>data[i][1];
        //allocate process ID
        data[i][0] = i+1;
    }

    //sort process according to burst time
    for(int i = 0; i<n ; i++){
        index = i;
        for(int j = i+1; j<n; j++){
            if(data[j][1] < data[index][1]){
                index = j;
            }
        }
        swap(data[i][1] , data[index][1]);

        swap(data[i][0] , data[index][0]);
    }

    //waiting time for first process is 0
    data[0][2] = 0;
    for(int i = 1; i<n; i++){
        data[i][2] = 0;
        for(int j = 0; j<i; j++){
            data[i][2] += data[j][1];
        }
        total += data[i][2];
    }

    float avg_wt = (total) / n;
    total = 0;
    cout<<"P\tBT\tWT\tTAT"<<endl;

    //calculation of turn around time and printing the data
    for(int i = 0; i<n; i++){
        data[i][3] = data[i][1] + data[i][2];
        total += data[i][3];
      cout<<"P"<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<endl;
    }

    float avg_tat = (total) / n;
    cout<<"Average waiting time = "<<avg_wt<<endl;
    cout<<"Average Turn around time = "<<avg_tat<<endl;
    return 0;
}
