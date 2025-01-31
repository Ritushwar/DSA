// Single Circular link list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructors
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructors
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            next = NULL;
            delete next;
        }
        cout<<"Memory free for the node with data: "<<value<<endl;
    }
};

void insertAtNode(Node* &tail, int element, int d){
    // search for element and insert after that node having value d
    Node* nodeToInsert = new Node(d);
    if(tail==NULL){  // empty list
        nodeToInsert->next = nodeToInsert;
        tail = nodeToInsert;
    }
    else{            // non empty list
        while(tail->data!=element){
        tail = tail->next;
    }
        nodeToInsert-> next = tail->next;
        tail->next = nodeToInsert;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail !=temp);
    cout<<endl;
}   

void deleteNode(Node* &tail, int element){
    Node* temp = NULL;
    do{
        temp = tail;
        tail = tail->next;
    }while(tail->data!=element);
    if(temp==tail){
        tail=NULL;
    }else{
    temp->next = tail->next;
    delete tail;
    tail = temp;
    }
}
int main(){
    Node* tail = NULL;
    insertAtNode(tail, 3, 1);
    print(tail);
    // insertAtNode(tail, 1, 2);
    // print(tail);
    // insertAtNode(tail, 2, 3);
    // print(tail);
    // insertAtNode(tail, 3, 4);
    // print(tail);
    // insertAtNode(tail, 2, 5);
    // print(tail);
    deleteNode(tail, 1);
    print(tail);
    insertAtNode(tail,5,7);
    print(tail);
    return 0;
}