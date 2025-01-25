// Array implemenatation of linear queue
#include<iostream>
using namespace std;
#define n 100
class queue{
    int *arr; 
    int front, rear; // for enqueue and dequeue operation

    public:
    queue(){
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    void enqueue(int x){
        if(rear==n-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue(){
        if(front>rear){
            return -1;
        }
        int item;
        item = arr[front];
        front++;
        return item;

    }
};
int main(){
    queue q1;
    int option, data;
    cout<<"Queue is created. "<<endl;
    while(true){
    cout<<"Choose the following operation"<<endl;
    cout<<"1.Enqueue the data"<<endl;
    cout<<"2.Dequeue the data"<<endl;
    cout<<"3.Exit"<<endl;
    cin>>option;
    if(option==1){
        cout<<"Enter the data to be enqueue"<<endl;
        cin>>data;
        q1.enqueue(data);
    }
    if(option==2){
        data = q1.dequeue();
        if(data == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
        cout<<"Dequeue Data was:"<<data<<endl;
        }
    }
    if(option==3){
        return 0;
    }
    }
    return 0;
}