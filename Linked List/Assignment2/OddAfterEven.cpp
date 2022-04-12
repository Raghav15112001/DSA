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

Node* OddEven(Node*head){
    Node*oh = nullptr;
    Node*ot = nullptr;
    Node*eh = nullptr;
    Node*et = nullptr;

    while(head != nullptr){
        if((head->data)%2 == 0){
            if(eh==nullptr) {
                eh=head;
                et= head;
            }
            else{
            et->next = head;
            et = head;
            }
        }
        else{
            if(oh==nullptr){
                oh=head;
                ot=head;
            }
            else{
            ot->next = head;
            ot=head;
            }
        }
        head=head->next;
    }
    ot->next = eh;
    et->next = nullptr;
    return oh;

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
    head = OddEven(head);
    print(head);    
    return 0;
}