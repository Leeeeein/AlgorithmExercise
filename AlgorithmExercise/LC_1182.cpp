#include "SolutionBaseClass.cpp"
#include <unordered_map>
class LC_1182 : public Solution {
public:
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		std::unordered_map<int, vector<int>> l;
		for (int i = 0; i < colors.size(); i++)
		{
			l[colors[i]].push_back(i);
		}
		vector<int> ret;
		for (auto& item : queries)
		{
			if (l[item[1]].size() == 0)
				ret.push_back(-1);
			else
				ret.push_back(helper(l[item[1]], item[0]));
		}
		return ret;
	}
	int helper(vector<int>& v, int i)
	{
		int l = 0, r = v.size() - 1;
		if (i < v[l]) return v[l] - i;
		if (i > v[r]) return i - v[r];
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (v[m] == i)
				return 0;
			if (v[m] > i)
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return min(abs(v[l] - i), abs(v[l - 1] - i));
	}
};