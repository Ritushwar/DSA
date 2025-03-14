#include<bits/stdc++.h>
using namespace std;
void selection_sort(int n, int arr[]){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    cout<<"Selection Sort is Done"<<endl;
}
int main(){
    int arr[5] = {1,7,2,9,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(size, arr);
    for(int i =0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}