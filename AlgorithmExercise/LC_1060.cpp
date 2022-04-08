#include "SolutionBaseClass.cpp"

class LC_1060 : public Solution
{
public:
	int missingElement(vector<int>& nums, int k) {
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int m = (l + r) / 2 + 1;
			int missed = nums[m] - nums[0] - m;
			if (missed < k)
			{
				l = m;
			}
			else
			{
				r = m - 1;
			}
		}
		return nums[0] + k + l;
	}
};