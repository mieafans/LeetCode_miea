// Author : miea
// Date   : 2014-11-3

/********************************************************************************** 
*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
*If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
*You may not alter the values in the nodes, only nodes itself may be changed.
*
*Only constant memory is allowed.
*
*For example,
*Given this linked list: 1->2->3->4->5
*
*For k = 2, you should return: 2->1->4->3->5
*
*For k = 3, you should return: 3->2->1->4->5
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
using namespace std;


  
 // Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:

    ListNode *reverseKGroup(ListNode *head, int k) {
		if(k == 1)
		{
			return head;
		}
		list<ListNode*> listNode;
		int cont = k;
		ListNode* beg = head, *sliceBeg = head, *pre = NULL;;

		while(sliceBeg != NULL)
		{
			while(cont != 0 && sliceBeg != NULL)
			{
				cont--;
				listNode.push_back(sliceBeg);
				sliceBeg = sliceBeg->next;
			}
			if(cont != 0)
			{
				break;
			}
			else
			{
				ListNode* p1 = listNode.back();
				listNode.pop_back();

				if(beg == head)
				{
					beg = p1;
				}
				if(pre != NULL)
				{
					pre->next = p1;
				}

				while(!listNode.empty())

				{
					ListNode* p2 = listNode.back();
					listNode.pop_back();
					p1->next = p2;
					p1 = p1->next;
				}
				pre = p1;
			}

			cont = k;
		}

		while(!listNode.empty() && pre != NULL)
		{
			ListNode* p3 = listNode.front();
			listNode.pop_front();
			pre->next = p3;
			pre = p3;
		}

		if(pre != NULL)
			pre->next = NULL;

		return beg;
    }
};
