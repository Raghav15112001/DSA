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

Node* midPoint(Node* head){
    Node* slow =head;
    Node* fast = head->next;
    while((fast!=nullptr)&&(fast->next != nullptr)){
        slow=slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}


Node* MergeSortLL(Node* head){
    if(head->next==nullptr){
        return head;
    }
Node*mid = midPoint(head);
Node*head2 = mid->next;
mid->next = nullptr;
Node*h1 = MergeSortLL(head);
Node*h2 = MergeSortLL(head2);
Node* finalHead = MergeTwoSortedLinkedList(h1,h2);
return finalHead;
}

int main()
{
    Node* head = takeInput_better();
    head = MergeSortLL(head);
    print(head);
    return 0;
}