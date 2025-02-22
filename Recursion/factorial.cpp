#include<bits/stdc++.h>
using namespace std;
int fac(int x){
    if(x==0 || x==1){
        return 1;
    }
    else{
        return x*fac(x-1);
    }
}
int main(){
    int x = 5;
    cout<<fac(x)<<endl;
    return 0;
}