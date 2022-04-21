#include "SolutionBaseClass.cpp"


class LC_239 : public Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		std::deque<int> q;
		vector<int >ret;
		for (int i = 0; i < nums.size(); i++)
		{
			while (!q.empty() && i - q.front() >= k)
				q.pop_front();
			while (!q.empty() && nums[i] >= nums[q.back()])
				q.pop_back();
			if (i >= k - 1)
			{
				if (!q.empty())
					ret.push_back(nums[q.front()]);
				else
					ret.push_back(nums[i]);
			}
			q.push_back(i);
		}
		return ret;
	}
};