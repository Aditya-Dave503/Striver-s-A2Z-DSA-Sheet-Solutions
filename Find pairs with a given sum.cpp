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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node* tail(Node* head){
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>>ans;
    if(head==NULL) return ans;
    Node* l=head;
    Node* r=tail(head);
    

    while(l->data<r->data){
        if(l->data+r->data==k){
            ans.push_back({l->data,r->data});
            l=l->next;
            r=r->prev;
        }
        else if(l->data+r->data<k) l=l->next;
        else r=r->prev;
}
return ans;
}
