/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    Node* temp=head;

    while(temp!=NULL && temp->next!=NULL){
        Node* nextnode=temp->next;
        while(nextnode!=NULL && nextnode->data==temp->data){
            Node* duplicate=nextnode;
            nextnode=nextnode->next;
            free(duplicate);
        }
        temp->next=nextnode;
        if(nextnode) nextnode->prev=temp;
        temp=temp->next;
    }
    return head;
}
