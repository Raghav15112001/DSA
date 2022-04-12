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

Node* Reverse(Node*head){
    if(head==nullptr || head->next==nullptr) return head;
     Node* x = Reverse(head->next);
     Node* temp = head->next;
     temp -> next = head;
     head->next = nullptr;   
     return x;   
}

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}

bool palindrome(Node*head){
    int length = lengthNode(head);
    int x = (length-1)/2;
    Node *temp = head;
    int count = 0;
    while(count<x){
        temp = temp->next;
        count++;
    }
    Node *h2 = Reverse(temp->next);
    temp->next=nullptr;
    print(head);
    cout<<endl;
    print(h2);
    cout<<endl;
    while((h2->data==head->data)){
        head=head->next;
        if(h2->next==nullptr){
            return true;
        }
        h2=h2->next;
    }

        return false;
    
}

int main()
{
    Node* head = takeInput_better();

    if(palindrome(head)){
        cout<<"It is Palindrome Linked List :)"<<endl;
    }
    else{
        cout<<"X Not a Palindrome X"<<endl;
    }    
    return 0;
}