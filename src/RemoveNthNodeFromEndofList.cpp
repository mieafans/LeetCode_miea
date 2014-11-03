// Author : miea
// Date   : 2014-11-3

/********************************************************************************** 
*Given a linked list, remove the nth node from the end of list and return its head.
*
*For example,
*
*Given linked list: 1->2->3->4->5, and n = 2.
*
*After removing the second node from the end, the linked list becomes 1->2->3->5.
*Note:
*Given n will always be valid.
*Try to do this in one pass.
**********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(head == NULL && n < 1)
			return NULL;
		ListNode* last = head;
		ListNode* cur = head;
		ListNode* pre = cur;

		n = n - 1;
		while(last != NULL && n)
		{
		    last = last->next;
			n--;
		}
		if(n != 0)
		{
			return head;
		}

		while(last->next != NULL)
		{
			last = last->next;
			if(pre != cur)
			{
				pre = pre->next;
			}
			cur = cur->next;
		}
		if(cur == pre)
		{
			pre = pre->next;
			delete cur;
			return pre;
		}
		else
		{
			pre->next = cur->next;
			delete cur;
		}

		return head;
        
    }
};
