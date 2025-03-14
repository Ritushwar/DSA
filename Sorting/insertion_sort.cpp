#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int n, int arr[]){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    cout<<"Insertion is Done"<<endl;
}
int main(){
    int arr[5] = {1,6,2,9,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(size, arr);
    for(int i =0; i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}