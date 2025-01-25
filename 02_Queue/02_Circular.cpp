// Circular queue
#include<iostream>
using namespace std;
#define capacity 5
class queue{
    int *arr;
    int front, rear, size;

    public:

    queue(){
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    void enqueue(int x){
        if(size==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear = (front + size)%capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue(){
        if(size==0){
            return -1;
        }
        int item;
        item = arr[front];
        front++;
        size--;
        return item;
    }
};
int main(){
    queue q1;
    int option, data;
    cout<<"Circular queue is created"<<endl;
    while(true){
        cout<<"Choose the following option"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>option;
        if(option==1){
            cout<<"Enter the data to be enqueue"<<endl;
            cin>>data;
            q1.enqueue(data);
        }
        if(option==2){
            data = q1.dequeue();
            if(data==-1){
                cout<<"Queue is empty"<<endl;
            }
            cout<<data<<endl;
        }
        if(option==3){
            return 0;
        }
    }
    return 0;
}