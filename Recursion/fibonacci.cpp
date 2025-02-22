#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}
int main(){
    int num = 5;
    for(int i=0;i<=num;i++){
        cout<<fib(i)<<" ";
    }
    return 0;
}