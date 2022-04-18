#include "SolutionBaseClass.cpp"

class  LC_287: public Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int np1 = nums.size();
		int l = 1, r = np1 - 1;
		int m;
		int cnt;
		while (l < r)
		{
			cnt = 0;
			m = (l + r) / 2;
			for (auto& item : nums)
			{
				cnt += item <= m;
			}
			if (cnt <= m)
				l = m + 1;
			else
				r = m;
		}
		return r;
	}
};