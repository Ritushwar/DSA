#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    // destructure
    ~Node(){
        int value = this->data;
        cout<<"Memory is free for the node with data: "<<value<<endl;
    }
};

// traversing a linked list
void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

 // find length of linked list
int getLength(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertAtHead(head, tail, d);
        return;
    }
    Node* currNode = head;
    Node* prevNode = NULL;
    int cnt = 1;
    while(cnt < position){
        prevNode = currNode;
        currNode = currNode->next;
        cnt++;
    }
    if(currNode->next==NULL){
        insertAtTail(tail, head, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    prevNode->next = nodeToInsert;
    nodeToInsert->prev = prevNode;
    nodeToInsert->next = currNode;
    currNode->prev = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next;
        delete temp;
    }
    else if(position==getLength(head)){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }
    else{
        Node* currNode = head;
        Node* prevNode = NULL;
        int cnt = 1;
        while(cnt<position-1){
            prevNode = currNode;
            currNode = currNode->next;
            cnt++;
        }
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        delete currNode;
        return;
    } 
}

int main(){
    int option, position, value;
    Node* head = NULL;
    Node* tail = NULL;
    cout<<"Operation in doubly link list: "<<endl;
    while(true){
        cout<<"Choose Option"<<endl;
        cout<<"1. Insert at head"<<endl;
        cout<<"2. Insert at tail"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete a node"<<endl;
        cout<<"5. Get length"<<endl;
        cout<<"6. Print List"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>option;
        if(option==1){
            cout<<"Enter data: ";
            cin>>value;
            insertAtHead(head,tail,value);
        }
        if(option==2){
            cout<<"Enter data: ";
            cin>>value;
            insertAtTail(tail, head,value);
        }
        if(option==3){
            label1:
            cout<<"Enter position: ";
            cin>>position;
            if(getLength(head)>position+1){
                cout<<"Enter valid position"<<endl;
                goto label1;
            }
            cout<<"Enter data: ";
            cin>>value;
            insertAtPosition(head, tail, position, value);
        }
        if(option==4){
            label2:
            cout<<"Enter position: ";
            cin>>position;
            if(position>getLength(head)){
                cout<<"Enter valid position"<<endl;
                goto label2;
            }
            deleteNode(head, tail, position);
        }
        if(option==5){
            cout<<"Length: "<<getLength(head)<<endl;
        }
        if(option==6){
            print(head);
        }
        if(option==7){
            return 0;
        } 
    }
    return 0;
}