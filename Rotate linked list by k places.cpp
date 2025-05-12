/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* findnthnode(ListNode* head, int k){
    ListNode* temp=head;
    int cnt=1;

    while(temp!=NULL){
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* temp=head;
        int len=1;

        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        
        if(k%len==0) return head;
        k=k%len;
        temp->next=head;
        
        ListNode* newnode=findnthnode(head,len-k);
        head=newnode->next;
        newnode->next=NULL;
        return head;
    }
};
