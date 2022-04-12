#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput_better(){
    int data;
    cin>>data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head =newNode;
            tail =newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void printReverseLL(Node* head){
    if(head==nullptr) return;
    printReverseLL(head->next);
    cout<<head->data<<" ";
    return;
}

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}


int main()
{   
    Node* head = takeInput_better();
    cout<<"Printing Reverse Order of Linked List: ";
    printReverseLL(head);

    return 0;
}