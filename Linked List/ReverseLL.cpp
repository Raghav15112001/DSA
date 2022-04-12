#include<iostream>
using namespace std;
#include "Node.cpp"

class Pair{
    public:
    Node* head;
    Node* tail;
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
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}


Node* Reverse(Node*head){
    if(head==nullptr || head->next==nullptr) return head;
     Node* x = Reverse(head->next);
     Node* temp = head->next;
     temp -> next = head;
     head->next = nullptr;   
     return x;   
}

Pair Reverse_2(Node*head){
    if(head==nullptr || head->next==nullptr){
        Pair ans;
        ans.head = head;
        ans.tail=head;
        return ans;
    } 
     Pair ans = Reverse_2(head->next);
     ans.tail->next = head;
     head->next = nullptr;
     ans.tail=head;
     return ans;   
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
    // head = Reverse(head);
    // print(head);
    Pair ans = Reverse_2(head);
    print(ans.head);
    return 0;
}