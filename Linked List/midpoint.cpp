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

void midPoint(Node* head){
    Node* slow =head;
    Node* fast = head->next;
    while((fast!=nullptr)&&(fast->next != nullptr)){
        slow=slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<endl;
}
int main()
{
    Node* head = takeInput_better();
    midPoint(head);
    return 0;
}