#include "SolutionBaseClass.cpp"

class LC_340: public Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (k == 0) return 0;
		int l = 0;
		std::unordered_map<char, int> m;
		int ret = 0;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (m[s[i]] == 0)
				cnt++;
			m[s[i]]++;
			while (cnt > k)
			{
				m[s[l]] -= 1;
				if (m[s[l]] == 0)
					cnt--;
				l++;
			}
			ret = max(ret, i - l + 1);
		}
		return ret;
	}
};