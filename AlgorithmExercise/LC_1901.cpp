#include "SolutionBaseClass.cpp"

class LC_1901 : public Solution
{
public:
	vector<int> findPeakGrid(vector<vector<int>>& mat) {
		int up = 0, down = mat.size() - 1;
		int mid = 0, mIdx = 0;
		while (up <= down)
		{
			mid = (up + down) / 2;
			int colV_u = -1;
			int colV_d = -1;
			if (mid - 1 >= 0)
				colV_u = get_idx(mat, mid - 1, mIdx);
			if (mid + 1 <= mat.size() - 1)
				colV_d = get_idx(mat, mid + 1, mIdx);
			int colV = get_idx(mat, mid, mIdx);
			if (colV >= colV_u && colV >= colV_d)
			{
				break;
			}
			else if (colV > colV_u)
			{
				up = mid + 1;
			}
			else
			{
				down = mid - 1;
			}
		}
		return { mid, mIdx };
	}
	int get_idx(vector<vector<int>>& mat, int row, int& idx)
	{
		int m = INT_MIN;
		for (int i = 0; i < mat[row].size(); i++)
		{
			if (mat[row][i] > m)
			{
				m = mat[row][i];
				idx = i;
			}
		}
		return m;
	}
};