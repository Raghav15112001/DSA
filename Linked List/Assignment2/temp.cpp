#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
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

void print(Node *head){
    while(head != nullptr){
        cout<< head ->data << " ";
        head = head -> next;
    }
}

int lenLL(Node*head){
    int length=0;
    while(head!=nullptr){
        head=head->next;
        length++;
    }
    return length;
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

Node* Merge(Node*h1,Node*h2){
    Node*fhead = nullptr;
    Node*ftail = nullptr;
if((h1->data)<=(h2->data)){
            fhead = h1;
            ftail = h1;
            h1= h1->next;
        }
        else{
            ftail = h2;
            fhead = h2;
            h2=h2->next;
        }
    while((h1!=nullptr) && (h2!=nullptr)){
        if((h1->data)<=(h2->data)){
            ftail->next = h1;
            ftail=h1;
            h1=h1->next;
        }
        else{
            ftail->next=h2;
            ftail=h2;
            h2=h2->next;
        }
    }
    if(h1==nullptr){
        ftail->next = h2;
    }
    else{
        ftail->next = h1;
    }

return fhead;
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
Node* finalHead = Merge(h1,h2);
return finalHead;
}



int main()
{
    Node* head = takeInput_better();
    print(head);
    cout<<"\n"<<lenLL(head)<<endl;
    head = MergeSortLL(head);
    print(head);
    return 0;
}