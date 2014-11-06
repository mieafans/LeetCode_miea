// Author : miea
// Date   : 2014-11-6

/********************************************************************************** 
*Given a linked list, determine if it has a cycle in it.
*
*Follow up:
*Can you solve it without using extra space?
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;



 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        ListNode* p1 = head, *p2 = head;
        while(p2->next != NULL && p2->next->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
            
            if(p1 == p2)
            {
                return true;
            }
        }
        return false;
    }
};
