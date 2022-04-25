#include "SolutionBaseClass.cpp"

class LC_49 : public Solution
{
public:
	string minWindow(string s, string t) {
		int l = 0;
		int b = 0, e = 0;
		std::unordered_map<char, int> m_t;
		std::unordered_map<char, int> m_w;
		int cnt = 0;
		int len = INT_MAX;
		int beg = 0;
		for (auto& c : t)
			m_t[c]++;
		for (int i = 0; i < s.size(); i++)
		{
			if (m_t[s[i]] != 0)
			{
				m_w[s[i]] += 1;
			}
			if (m_w[s[i]] <= m_t[s[i]] && m_t[s[i]] != 0)
			{
				cnt += 1;
			}
			if (cnt != t.size())
			{
				continue;
			}
			while (cnt == t.size())
			{
				if (i - l + 1 < len)
				{
					len = i - l + 1;
					beg = l;
				}
				if (m_t[s[l]] != 0)
					m_w[s[l]] -= 1;
				if (m_w[s[l]] < m_t[s[l]])
				{
					cnt--;
				}
				l++;
			}
		}
		if (len != INT_MAX)
			return s.substr(beg, len);
		return "";
	}
};