#include "SolutionBaseClass.cpp"
#include <numeric>
class LC_239 : public Solution {
public:
	int maximizeSweetness(vector<int>& sweetness, int k) {
		int sum = accumulate(sweetness.begin(), sweetness.end(), 0);
		int low = 1, high = sum / (k + 1) + 1;
		while (low < high)
		{
			int mid = low + (high - low) / 2;
			int segs = helper(sweetness, mid);
			if (segs >= k + 1)
			{
				low = mid + 1;
			}
			else if (segs < k + 1)
			{
				high = mid;
			}
		}
		return low - 1;
	}

	int helper(vector<int>& sweetness, int mid)
	{
		int num_seg = 0;
		int cur_sweet = 0;
		for (auto& item : sweetness)
		{
			cur_sweet += item;
			if (cur_sweet >= mid)
			{
				num_seg += 1;
				cur_sweet = 0;
			}
		}
		return num_seg;
	}
};