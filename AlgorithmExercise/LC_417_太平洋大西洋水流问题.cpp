#include "SolutionBaseClass.cpp"

class LC_417 : public Solution
{
public:
	void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& oce)
	{
		if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size())
			return;
		if (oce[x][y] == 1)
			return;
		oce[x][y] = 1;
		if (x + 1 < heights.size() && heights[x][y] <= heights[x + 1][y])
			dfs(heights, x + 1, y, oce);
		if (y + 1 < heights[0].size() && heights[x][y] <= heights[x][y + 1])
			dfs(heights, x, y + 1, oce);
		if (x - 1 >= 0 && heights[x][y] <= heights[x - 1][y])
			dfs(heights, x - 1, y, oce);
		if (y - 1 >= 0 && heights[x][y] <= heights[x][y - 1])
			dfs(heights, x, y - 1, oce);
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>> pac(heights.size(), vector<int>(heights[0].size(), 0));
		vector<vector<int>> atl(heights.size(), vector<int>(heights[0].size(), 0));
		for (int i = 0; i < heights.size(); i++)
		{
			dfs(heights, i, 0, pac);
		}
		for (int i = 0; i < heights[0].size(); i++)
		{
			dfs(heights, 0, i, pac);
		}
		for (int i = heights.size() - 1; i >= 0; i--)
		{
			dfs(heights, i, heights[0].size() - 1, atl);
		}
		for (int i = heights[0].size() - 1; i >= 0; i--)
		{
			dfs(heights, heights.size() - 1, i, atl);
		}
		vector<vector<int>> ret;
		for (int i = 0; i < heights.size(); i++)
		{
			for (int j = 0; j < heights[0].size(); j++)
			{
				if (pac[i][j] == 1 && atl[i][j] == 1)
					ret.push_back({ i,j });
			}
		}
		return ret;
	}
};