
#include <malloc.h>
#include "stdlib.h"
#include "stdio.h"
struct ListNode {
      int val;
      struct ListNode *next;
  };



int main() {
    struct ListNode * head = malloc(sizeof(struct ListNode));
    struct ListNode * preVal = head;
    int tmp = 1;
    int j = 0;
    while (j < 6)
    {
        preVal ->val = tmp;
        preVal = preVal -> next;
        tmp++;
        ++j;
    }
    printf("%d\n",preVal -> next);

    struct ListNode * cur;
    struct ListNode * pre;
    struct ListNode * mNext;
    while(head -> next) {
        cur = head -> next;
        pre = head;
        mNext = cur -> next;
        pre = cur;
        cur = mNext;
    }
    return cur
    return 0;


}