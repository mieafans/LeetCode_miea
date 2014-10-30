// Author : miea
// Date   : 2014-10-30

/********************************************************************************** 
*Given n non-negative integers a1, a2, ..., 
*an, where each represents a point at coordinate (i, ai). 
*n vertical lines are drawn such that the two endpoints of line i is at (i, ai) 
*and (i, 0). Find two lines, which together with x-axis forms a container, 
*such that the container contains the most water.
*
*Note: You may not slant the container.
**********************************************************************************/

#include <vector>
#include <math.h>

using namespace std;
class Solution {
public:
	int maxArea(vector<int> &height) {
		int mx  = 0;
		int len = height.size();
		int low = 0, high = len - 1;
		while(high > low)
		{
			mx = max(mx, (high - low)* min(height[high], height[low]));
			if(height[high] <= height[low])
				high--;
			else if(height[high] >  height[low])
				low++;
		}
		return mx;
	}
};
