#include<bits/stdc++.h>
using namespace std;
struct item{
    int value;
    int priority;
};

item pr[100];
int Size=-1;
void enqueue(int value, int priority){
    Size++;
    pr[Size].value=value;
    pr[Size].priority=priority;  
}
int peek(){
    int highestPriority=INT_MIN;
    int ind=-1;
    for(int i=0; i<Size;i++){
        if(highestPriority==pr[i].priority && ind > -1
           && pr[i].value > pr[ind].value){
            highestPriority = pr[i].priority;
            ind = i;
           }
        else if(highestPriority < pr[i].priority){
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

int dequeue(){
    int ind = peek();
    int value = pr[ind].value;
    for(int i = ind; i<Size; i++){
        pr[i] = pr[i+1];
    }
    Size--;
    return value;
}
int main(){
    enqueue(10,8);
    enqueue(14,3);
    enqueue(16,2);
    
    int ind = peek();
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    return 0;
}