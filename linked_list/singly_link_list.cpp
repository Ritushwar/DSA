// Singly link list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;   // pointer of type node used to store the address of another node

    Node(int data){
       this -> data = data;
       this -> next = NULL; 
    }
     ~Node(){
        int value = this -> data;
        if(this-> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
     }

};

void InsertAtHead(Node* &head, int d){   // use & for change in original and not making copy of it.
        Node* temp = new Node(d);        // create a new node to be inserted
        temp -> next = head;
        head = temp;                     // making temp node to head node for next
}

void Print(Node* &head){
        Node* temp = head;       // create a new node and point it to head
        while(temp!= NULL){      // print until last node
            cout<<temp->data<<" ";   // print value
            temp = temp->next;           // point to next node
        }
        cout<<endl;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);       // create a new temporary node
    tail -> next = temp;            // point tail to temp
    tail = tail -> next;            // tail node is temp node
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){     // insert at first position
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){   // if position is at last same as InsertAtTail
        InsertAtTail(tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    // delete for first or start node
    if(position==1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    // delete for any position or tail
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr-> next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    Print(head);

    InsertAtHead(head, 10);
    Print(head);

    InsertAtHead(head, 15);
    Print(head);

    InsertAtTail(tail, 20);
    Print(head);

    InsertAtTail(tail, 25);
    Print(head);

    InsertAtPosition(head,tail, 4, 200);
    Print(head);

    InsertAtPosition(head,tail, 7, 300);
    Print(head);

    deleteNode(4, head);
    Print(head);

    cout<< tail->data<<endl;
    cout<< tail->next<<endl;
    return 0;
} 