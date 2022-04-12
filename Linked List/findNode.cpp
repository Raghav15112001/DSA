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

int SearchNode(Node* head,int x){
    if(head == nullptr){
        return -1;
    }
    if(head->data==x){
        return 0;
    }
    int count = SearchNode(head->next,x);
    if(count!=-1) return count+1;
    else return count;
}

int main()
{
    Node* head = takeInput_better();
    int x;
    cin>>x;
    int index = SearchNode(head,x);
    if(index!=-1){
    cout<<"Required value is at index : "<<index<<endl;
    }
    else{
        cout<<"X Required value not exist in Linked List !!"<<endl;
    }

    return 0;
}