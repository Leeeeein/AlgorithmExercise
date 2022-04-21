#include "SolutionBaseClass.cpp"

class LC_1004 : public Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		std::queue<int> q;
		int l = 0, r = 0, m = 0;
		int ret = 0;
		int rcd = k;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0 && k == 0)
				l = i + 1;
			else if (nums[i] == 0 && rcd == 0 && !q.empty())
			{
				int t = q.front();
				q.pop();
				l = t + 1;
				q.push(i);
			}
			else if (nums[i] == 0 && rcd > 0)
			{
				rcd--;
				q.push(i);
			}

			ret = max(ret, i - l + 1);
		}
		return ret;
	}
};