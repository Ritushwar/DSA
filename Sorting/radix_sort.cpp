#include<bits/stdc++.h>
using namespace std;
int getMax(int *arr, int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx){
            mx = arr[i];
        }
    }
    return mx;
}
void countSort(int *arr, int n, int pos){
    int output[n];
    int i, count[10] = {0};
    for(i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }

    // change count[i] so that count[i]
    for(i=1; i<10;i++){
        count[i] += count[i-1];
    }

    // Build the output array
    for(i=n-1; i>=0;i--){
        output[count[(arr[i] / pos)%10]-1] = arr[i];
        count[(arr[i] / pos) %10]--;
    }
    //copy value to original array
    for(i=0;i<n;i++){
        arr[i] = output[i];
    }
}
void radix_sort(int *arr, int n){
    // Find the maximum number
    // know the number of digits

    int m = getMax(arr,n);

    // Do counting sort for every digits
    for(int pos=1; m/pos > 1; pos*=10){
        countSort(arr, n, pos);
    }
    cout<<"Radix Sort is done"<<endl;
}
int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}