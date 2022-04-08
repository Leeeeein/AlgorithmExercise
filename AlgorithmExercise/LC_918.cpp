#include "SolutionBaseClass.cpp"

class LC_918 : public Solution
{
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int maxV = INT_MIN, minV = INT_MAX, cnt = 0;
		int m = INT_MIN;
		vector<int> dp_max(nums.size(), 0);
		vector<int> dp_min(nums.size(), 0);

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > m)
				m = nums[i];
			cnt += nums[i];
			if (i == 0)
			{
				dp_max[i] = nums[i];
				dp_min[i] = nums[i];
			}
			else
			{
				dp_max[i] = max(dp_max[i - 1] + nums[i], nums[i]);
				dp_min[i] = min(dp_min[i - 1] + nums[i], nums[i]);
			}
			maxV = max(maxV, dp_max[i]);
			minV = min(minV, dp_min[i]);
		}
		if (m <= 0)
			return m;
		return max(maxV, cnt - minV);
	}
};