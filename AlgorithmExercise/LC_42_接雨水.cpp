#include "SolutionBaseClass.cpp"

class LC_49 : public Solution
{
public:
	int trap(vector<int>& height) {
		int max = 0;
		stack<int> helper;
		int res = 0;
		for (int i = 0; i < height.size(); i++)
		{
			if (i == 0)
			{
				max = i;
				helper.push(i);
				continue;
			}
			if (height[i] < height[helper.top()])
			{
				helper.push(i);
			}
			else
			{
				while (!helper.empty() && height[i] >= height[helper.top()])
				{
					int t = helper.top();
					helper.pop();
					if (!helper.empty())
						res += (min(height[i], height[helper.top()]) - height[t]) * (i - helper.top() - 1);
				}
				if (helper.empty())
				{
					max = i;
				}
				helper.push(i);
			}
		}
		return res;
	}
};