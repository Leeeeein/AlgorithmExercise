#include "SolutionBaseClass.cpp"

class LC_159 : public Solution
{
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		/*给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t ，并返回该子串的长度。   "ccaacccbbb" "ccaaccc"*/
		int l = 0, r = 0;
		int ret = 0;
		std::unordered_map<char, int> m;
		m.insert({ s[0], 1 });
		while (true)
		{
			if (r == s.size() - 1)
			{
				ret = max(ret, r - l + 1);
				break;
			}
			if (m.size() < 2)   // m中元素数量小于2时
			{
				r += 1;
				if (m.find(s[r]) == m.end())
				{
					m.insert({ s[r],0 });
				}
				m[s[r]]++;
			}
			else    // m中元素数量等于2时
			{
				r += 1;
				if (m.find(s[r]) != m.end())
				{
					m[s[r]]++;
				}
				else
				{
					while (m.size() == 2)
					{
						int tmp = l;
						m[s[l]]--;
						l += 1;
						if (m[s[tmp]] == 0)
						{
							m.erase(s[tmp]);
						}
					}
					m.insert({ s[r], 1 });
				}
			}
			ret = max(ret, r - l + 1);

		}
		return ret;
	}
};