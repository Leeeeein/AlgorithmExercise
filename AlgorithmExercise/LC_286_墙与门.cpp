#include "SolutionBaseClass.cpp"


class LC_286 : public Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		for (int i = 0; i < rooms.size(); i++)
		{
			for (int j = 0; j < rooms[0].size(); j++)
			{
				if (rooms[i][j] == 0)
				{
					helper(rooms, i, j, 0);
				}
			}
		}
	}
	void helper(vector<vector<int>>& rooms, int x, int y, int c)
	{
		if (x < 0 || x > rooms.size() - 1 || y < 0 || y > rooms[0].size() - 1 || rooms[x][y] <= c)
		{
			return;
		}
		if (c != 0 && rooms[x][y] <= c)
		{
			return;
		}
		rooms[x][y] = min(c, rooms[x][y]);
		helper(rooms, x - 1, y, c + 1);
		helper(rooms, x + 1, y, c + 1);
		helper(rooms, x, y - 1, c + 1);
		helper(rooms, x, y + 1, c + 1);
	}
};