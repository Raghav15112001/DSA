#include <iostream>
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

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = nullptr;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head =newNode;
        }
        else{
            Node *temp = head;
            while(temp->next !=nullptr){
                temp = temp->next;
            }
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}


Node* insertNode(Node *head,int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i==0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while(temp!=nullptr && count<i-1){
        temp = temp->next;
        count ++;
    }
    if(temp!=nullptr){
        newNode->next = temp->next;
        temp->next = newNode;
    }

return head;
}


Node* insertNodeRecursively(Node *head,int i, int data){
    if(head == nullptr){
        
        return head;
    }
    if(i==0){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = insertNodeRecursively(head->next,i-1,data);
    head->next = temp;
    return head;
}


Node* deleteNode(Node *head,int i){

    int count = 0;
    Node *temp = head;

    if(i==0){
        Node* a = head;
        head = head->next;
        delete a;
        return head;
    }

    while(temp!=nullptr && count<i-1){
        temp = temp->next;
        count ++;
    }
    if(temp!=nullptr){
        Node* a = temp->next;
        Node* b = a->next;
        temp->next=b;
        delete a;
    }

return head;
}

Node* deleteNodeRecursively(Node* head,int i){
    if(head == nullptr){
        return head;
    }

    if(i==0){
        Node *a = head;
        head = head->next;
        delete a;
        return head;
    }
    Node* temp = deleteNodeRecursively(head->next,i-1);
    head->next = temp;
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


void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }

/*
    temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
*/

}

int main(){
    
    Node *head = takeInput_better();
    print(head);
    cout<<endl;
    int i,data;
    cin>>i>>data;
    
    // head = insertNode(head,i,data);
    head = insertNodeRecursively(head,i,data);
    print(head);
    cout<<endl;
    int n;
    cin>>n;
    head = deleteNodeRecursively(head,n);
    print(head);
    /*
    cout<<"Type the index of Node, you want to delete : ";
    int n;
    cin>>n;
    head = deleteNode(head,n);
    print(head);
    cout<<endl;
    int length = lengthNode(head);
    cout<<"Length Of Linked List: "<<length<<endl;
*/

/*
    Node n1(1);
    Node*head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);
    print(head);

    Node *n6 = new Node(6);
    Node *headDy = n6;
    Node *n7 = new Node(7);
    n6->next = n7;
    print(headDy);
*/
}