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
ListNode* find(ListNode* temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        temp=temp->next;
        k--;
    }
    return temp;
}

ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;

    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        ListNode* newhead=NULL;

        while(temp!=NULL){
            ListNode* kthnode=find(temp,k);
            if(kthnode==NULL){
                if(prevnode) prevnode->next=temp;
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            ListNode* reversedhead=reverse(temp);
            
            if(newhead==NULL) newhead=reversedhead;
            if(prevnode!=NULL) prevnode->next=reversedhead;

            prevnode=temp;
            temp=nextnode;
        }
        return newhead? newhead: head;
    }
};
