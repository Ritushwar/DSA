#include<bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid -s +1;
    int len2 = e - mid;

    int *first = new int[len1];  // making first array
    int *second = new int[len2]; // making second array

    // copy value from arr to first and second array
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge both array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++] = second[index2++];
    }


}

void merge_sort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    //left part sort
    merge_sort(arr, s, mid);

    //right part sort
    merge_sort(arr, mid+1, e);

    //merge both
    merge(arr, s, e);

}

int main(){
    int arr[5] = {2,5,1,6,9};
    int n = 5;
    merge_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}