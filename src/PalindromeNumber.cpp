// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
* 
*Given a string, find the length of the longest substring without repeating characters. 
*For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
*which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*              
**********************************************************************************/


class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0 || x == 10) 
			return false;
		if(x < 10)
			return true;
		bool flag = true;
		int left = x;
		int right = x;

		int count = 10;
		while(x/count >= 10)
		{
			count*=10;
		}

		while(left >= 10)
		{
			if(left/count == right%10)
			{
				left%=count;
				right/=10;
				count/=10;
			}
			else
			{
				flag = false;
				break;
			}
		}

		return flag;

	}
};


//int main()
//{
//	Solution so;
//	bool ret = so.isPalindrome(1001);
//	return 0;
//}