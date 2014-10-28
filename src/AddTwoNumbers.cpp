// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
*You are given two linked lists representing two non-negative numbers. 
*The digits are stored in reverse order and each of their nodes contain a single digit. 
*Add the two numbers and return it as a linked list.
*
*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*Output: 7 -> 0 -> 8
**********************************************************************************/

#include "stddef.h"


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		ListNode* tmpL1 = l1;
		ListNode* tmpL2 = l2;

		ListNode* preNode = NULL;
		ListNode* nowNode = NULL;
		ListNode* begNode = NULL;
		int carry = 0;
		int sum = 0;

		while(tmpL1 != NULL || tmpL2 != NULL)
		{
			 if(preNode == NULL)
			 {
				 sum = (tmpL1?tmpL1->val:0) + (tmpL2?tmpL2->val:0);
				 carry = sum/10;

				 preNode = new ListNode(sum%10);
				 tmpL1 = tmpL1?tmpL1->next:NULL;
				 tmpL2 = tmpL2?tmpL2->next:NULL;
				 begNode = preNode;
				 continue;
			 }

			 sum = (tmpL1?tmpL1->val:0) + (tmpL2?tmpL2->val:0) + carry;
			 carry = sum/10;

			 nowNode = new ListNode(sum%10);
			 preNode->next = nowNode;
			 preNode = nowNode;
			 tmpL1 = tmpL1?tmpL1->next:NULL;
			 tmpL2 = tmpL2?tmpL2->next:NULL;

		}
		if(carry)
		{
		   nowNode = new ListNode(carry);
		   preNode->next = nowNode;
		}

		return begNode;
        
    }
};


int main()
{
	Solution so;
	ListNode no1(1);
	ListNode no2(9);
	ListNode no4(9);
	no4.next = &no2;
	ListNode* no3 = so.addTwoNumbers(&no1, &no4);
	//system("pause");
	return 0;
}
