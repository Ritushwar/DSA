#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int n, int arr[]){
    for(int i = 1; i<n;i++){
        for(int j =0; j<n-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1], arr[j]);
            }
        }
    }
    cout<<"Bubble Sort is done"<<endl;
}
int main(){
    int arr[6] = {1,4,2,9,3,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(size, arr);
    for(int i =0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}