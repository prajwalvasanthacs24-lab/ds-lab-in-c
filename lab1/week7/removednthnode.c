/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) { 
     struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
     newnode->next=head;
    struct ListNode* ptr=newnode;
     struct ListNode* prev=newnode;
     for(int i=0;i<=n;i++){
        
        ptr=ptr->next;
     }
     while(ptr !=NULL){
        prev=prev->next ;
        ptr=ptr->next;
         

     }
    struct ListNode* t=prev->next;
    prev->next=t->next;
    free(t);
    struct ListNode* newHead = newnode->next;

    free(newnode);
    return newHead;
} 
