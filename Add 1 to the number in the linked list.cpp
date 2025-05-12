/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

 int helper(Node* head){
     if(head==NULL) return 1;

    int carry=helper(head->next);
    head->data=head->data+carry;
    carry=head->data/10;
    head->data=head->data%10;
    return carry; 
 }

Node *addOne(Node *head)
{
    int carry=helper(head);

    if(carry){
        Node* newnode=new Node(1);
        newnode->next=head;
        return newnode;
    }
    return head;
}
