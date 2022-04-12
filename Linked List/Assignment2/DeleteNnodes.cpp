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

void print(Node *head){
    if(head==nullptr)return;
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}

Node* DeleteNnodes(Node* head,int m,int n){
    Node* temp = head;
    Node* P = temp;
    
    while(temp!=nullptr){
    int M =m;
    int N = n;
    while(M>0 && temp!=nullptr){
        P=temp;
        temp = temp->next;
        M--;
    }
    while(N>0 && temp!=nullptr){
        Node* a = temp;
        temp=temp->next;
        delete a;
        N--;
    }
    P->next = temp;
    P=P->next;
}
return head;
}



int main()
{   
    int t;
    cin>>t;
    while(t--){
    Node* head = takeInput_better();
    int n,m;
    cin>>m>>n;
    head = DeleteNnodes(head,m,n);
    print(head);
    }
    return 0;
}