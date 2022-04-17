#include "SolutionBaseClass.cpp"

class LC_1229 : public Solution
{
public:
	vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

		sort(slots1.begin(), slots1.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
		});
		sort(slots2.begin(), slots2.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
		});

		int p1 = 0, p2 = 0;
		int n1 = slots1.size();
		int n2 = slots2.size();
		int overlap = 0;
		int begin = -1;
		while (p1 < n1 && p2 < n2)
		{
			// 如果有交集
			if (slots1[p1][0] >= slots2[p2][0] && slots1[p1][0] < slots2[p2][1])
			{
				overlap = min(slots1[p1][1], slots2[p2][1]) - slots1[p1][0];
			}
			if (slots2[p2][0] >= slots1[p1][0] && slots2[p2][0] < slots1[p1][1])
			{
				overlap = min(slots1[p1][1], slots2[p2][1]) - slots2[p2][0];
			}
			if (overlap >= duration)
			{
				begin = max(slots1[p1][0], slots2[p2][0]);
				break;
			}
			// 如果没有交集
			if (slots1[p1][1] < slots2[p2][1])
				p1++;
			else
				p2++;
		}
		if (begin == -1)
			return {};
		return { begin, begin + duration };
	}
};