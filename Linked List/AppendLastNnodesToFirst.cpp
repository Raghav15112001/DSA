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
int lengthNode(Node* head){
    if(head==nullptr){
        return 0;
    }
    head=head->next;
    int count = lengthNode(head);
    return count+1;
}


Node* AppendLastNodesToFirst(Node*head,int n){
    Node* tail=head;
    Node* temp=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    // cout<<"I'm at tail and my Data is: "<<tail->data<<endl;
    int length = lengthNode(head);
    // cout<<"My length is: "<<length<<endl;
    int count = 0;
    while(count<(length-n-1)){
        temp=temp->next;
        count++;
    }
    // cout<<"My temp data is: "<<temp->data<<endl;
    Node* h2=temp->next;
    temp->next = nullptr;
    tail->next = head;
    head=h2;

    return head;
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
    int n;
    cin>>n;
    head = AppendLastNodesToFirst(head,n);
    print(head);
    return 0;
}