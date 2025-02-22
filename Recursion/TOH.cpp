#include<bits/stdc++.h>
using namespace std;
void call_tower(int n, char s, char a, char d){
    if(n==1){
        cout<<s<<" to "<<d<<endl;
        return;
    }
    call_tower(n-1, s,d,a);
    cout<<s<<" to "<<d<<endl;
    call_tower(n-1, a,s,d);
    return;
}

int main(){
    call_tower(3,'s', 'a', 'd');
    return 0;
}