#include<bits/stdc++.h>
using namespace std;
struct my_list{
    int info;
    int next;
};
int Size = 0;
my_list l1[20];
void get_node(int indx){
    if(indx>Size){
        cout<<"Index out of bound"<<endl;
    }
    else{
    cout<<"info: "<<l1[indx].info<<endl;
    cout<<"next: "<<l1[indx].next<<endl;
    }
}

void insafter(int info){  // insert and item to list
    if(Size < 20){
    l1[Size].info = info;
    l1[Size].next = Size+1;
    Size++;
    }
    else{
        cout<<"Sorry list is out of Bound"<<endl;
    }
}

void free_node(int indx){
    if(indx>=Size || l1[indx].next==-1){
        cout<<"Invalid Operation"<<endl;
        return;
    }
    for(int i = 0; i < Size; i++){
        if(l1[i].next == indx){
            l1[i].next == l1[i+1].next;
            break;
        }
    }
    l1[indx].info = 0;
    l1[indx].next = -1;
}

int main(){
    int option, value, index;
    cout<<"Operation in list"<<endl;
    while(true){
        cout<<"Choose one option"<<endl;
        cout<<"1. Insert Item"<<endl;
        cout<<"2. Free Node"<<endl;
        cout<<"3. Get Node"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>option;
        if(option==1){
            cout<<"Enter value(int): ";
            cin>>value;
            insafter(value);
        }
        if(option==2){
            cout<<"Enter index: ";
            cin>>index;
            free_node(index);
        }
        if(option==3){
            cout<<"Enter index: ";
            cin>>index;
            get_node(index);
        }
        if(option==4){
            return 0;
        }
    }
}