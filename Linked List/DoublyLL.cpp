#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev=nullptr;
        Node* next=nullptr;
    Node(int data){
        this->data = data;
    }
};

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
            newNode->prev = tail;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int main()
{   
    Node * head = takeInput_better();

    head = head->next->next->next;
    cout<<head->data<<endl;
    head = head->prev;
    cout<<"Doubly Example: "<<head->data<<endl;
    
    return 0;
}