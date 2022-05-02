#include "SolutionBaseClass.cpp"

class LC_49 : public Solution{
public:
	int find(unordered_map<int, int>& m, int k)
	{
		if (m[k] != k)
		{
			return find(m, m[k]);
		}
		return k;
	}
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, int> parent;
		for (auto& p : pid)
		{
			parent[p] = p;
		}
		for (int i = 0; i < pid.size(); i++)
		{
			if (pid[i] == kill)
			{
				parent[pid[i]] = pid[i];
				continue;
			}
			parent[pid[i]] = ppid[i];
		}
		vector<int> ret;
		for (int i = 0; i < pid.size(); i++)
		{
			int p = find(parent, pid[i]);
			if (p == kill)
			{
				ret.push_back(pid[i]);
			}
		}
		return ret;
	}
};