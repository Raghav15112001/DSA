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


void removeDuplicates(Node* head){
    if(head==nullptr){
        return;
    }
    Node* t1 = head;
    Node* t2 = head->next;
    while(t2!=nullptr){
        if(t2->data!=t1->data){
            t1->next=t2;
            t1=t2;
            t2=t2->next;
        }
        else{
            Node* a = t2;
            t2 = t2 -> next;
            delete a;
        }
    }
    t1->next=nullptr;

}

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}

int main()
{
    Node *head = takeInput_better();
    removeDuplicates(head);
    print(head);   
    return 0;
}