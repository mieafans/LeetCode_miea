// Author : miea
// Date   : 2014-11-3

/********************************************************************************** 
*Given a linked list, swap every two adjacent nodes and return its head.
*
*For example,
*Given 1->2->3->4, you should return the list as 2->1->4->3.
*
*Your algorithm should use only constant space.
*You may not modify the values in the list, only nodes itself can be changed.
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
		{
			return NULL;
		}
		if(head->next == NULL)
		{
			return head;
		}
		ListNode* pre = head;
		ListNode* cur, *nowHead, *beg;
		if(pre->next != NULL)
		{
			cur = pre->next;
			pre->next = cur->next;
			cur->next = pre;

			nowHead = cur;
			cur = pre;
		}
		
		while(cur->next != NULL && cur->next->next != NULL)
		{
			beg = cur;
			pre = cur->next;
			cur = pre->next;


			pre->next = cur->next;
			cur->next = pre;
			beg->next = cur;

			cur = pre;
			pre = beg->next;

		}

		return nowHead;
    }
};
