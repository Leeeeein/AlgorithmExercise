#include "SolutionBaseClass.cpp"

class LC_1868 : public Solution
{
	public:
		vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
			/*encoded1 = [[1,3],[2,1],[3,2]], encoded2 = [[2,3],[3,3]]Êä³ö: [[2,3],[6,1],[9,2]]*/
			auto p1 = encoded1.begin();
			auto p2 = encoded2.begin();
			auto pf = nullptr;
			vector<vector<int>> ret;
			while (p1 != encoded1.end())
			{
				if ((*p1)[1] == (*p2)[1])
				{
					if (!ret.empty() && (*p1)[0] * (*p2)[0] == ret.back()[0])
						ret.back()[1] += (*p1)[1];
					else
						ret.push_back({ (*p1)[0] * (*p2)[0], (*p1)[1] });
					p1++;
					p2++;
				}
				else if ((*p1)[1] < (*p2)[1])
				{
					if (!ret.empty() && (*p1)[0] * (*p2)[0] == ret.back()[0])
						ret.back()[1] += (*p1)[1];
					else
						ret.push_back({ (*p1)[0] * (*p2)[0], (*p1)[1] });
					(*p2)[1] -= (*p1)[1];
					p1++;
				}
				else
				{
					if (!ret.empty() && (*p1)[0] * (*p2)[0] == ret.back()[0])
						ret.back()[1] += (*p2)[1];
					else
						ret.push_back({ (*p1)[0] * (*p2)[0], (*p2)[1] });
					(*p1)[1] -= (*p2)[1];
					p2++;
				}
			}
			return ret;
		}
};