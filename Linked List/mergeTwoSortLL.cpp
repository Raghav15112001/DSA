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

Node* MergeTwoSortedLinkedList(Node* h1,Node* h2){
    Node* finalHead = nullptr;
    Node* finalTail = nullptr;
    if((h1->data)<=(h2->data)){
            finalHead = h1;
            finalTail = h1;
            h1= h1->next;
        }
        else{
            finalTail = h2;
            finalHead = h2;
            h2=h2->next;
        }
    while((h1!=nullptr) && (h2!=nullptr)){
        if((h1->data)<=(h2->data)){
            finalTail->next = h1;
            finalTail=h1;
            h1=h1->next;
        }
        else{
            finalTail->next=h2;
            finalTail=h2;
            h2=h2->next;
        }
    }
    if(h1==nullptr){
        finalTail->next = h2;
    }
    else{
        finalTail->next = h1;
    }

return finalHead;
}

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}

int main()
{
    Node* h1 = takeInput_better();
    Node* h2 = takeInput_better();
    Node* head = MergeTwoSortedLinkedList(h1,h2);
    print(head);
    return 0;
}