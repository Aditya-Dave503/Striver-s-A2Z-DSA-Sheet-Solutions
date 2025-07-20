/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* list1, Node* list2){
	Node* dnode=new Node(-1);
	Node* temp=dnode;

	while(list1!=NULL && list2!=NULL){
		if(list1->data < list2->data){
			temp->child=list1;
			temp=list1;
			list1=list1->child;
		}
		else{
			temp->child=list2;
			temp=list2;
			list2=list2->child;
		}
	}
	if(list1) temp->child=list1;
	else temp->child=list2;

	return dnode->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL) return head;

	Node* merged=flattenLinkedList(head->next);
	return merge(head,merged);
}
