#include<iostream>
using namespace std;
#include"Node.cpp"
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
int findNode(Node* head,int x){
    if(head==nullptr){
        return -1;
    }
   int tempPosition = findNode(head->next,x);
   if(head->data == x){
       return 0;
   }
   return tempPosition+1;
}



int main()
{   
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput_better();
        int x;
        cin>>x;
        int position = findNode(head,x);
        cout<<position<<endl;
    }
    
    return 0;
}