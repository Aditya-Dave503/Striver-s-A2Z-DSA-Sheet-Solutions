/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* zerohead=new Node(-1);  Node* zero=zerohead;
    Node* onehead=new Node(-1);   Node* one=onehead;
    Node* twohead=new Node(-1);   Node* two=twohead;

    Node* temp=head;

    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    Node* newhead=zerohead->next;
    zero->next=(onehead->next)?onehead->next:twohead->next;
    one->next=twohead->next;
    two->next=NULL;
    delete zerohead;
    delete onehead;
    delete twohead;
    return newhead;
}
