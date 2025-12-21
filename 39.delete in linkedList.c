#include <stdio.h> 
#include <stdlib.h>



struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* removeElements(struct ListNode* head, int val) {

    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* ptr = head;

    while (ptr != NULL) {
        struct ListNode* p = ptr->next;

        if (p != NULL && p->val == val) {
            ptr->next = p->next;
            free(p);
        } else {
            ptr = ptr->next;
        }
    }

    return head;
}



    

int main()
{



    return 0 ; 
}