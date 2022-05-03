#include "SolutionBaseClass.cpp"

class LC_863 : public Solution {
public:
	unordered_map<TreeNode*, TreeNode*> m;
	unordered_map<TreeNode*, int> ed;
	TreeNode* tar = new TreeNode(-2);
	void inOrder(TreeNode* root, TreeNode*& pre, TreeNode* target)
	{
		if (root == nullptr)
			return;
		if (root == target)
			this->tar = root;
		m[root] = pre;
		inOrder(root->left, root, target);
		inOrder(root->right, root, target);
	}

	void bfs(TreeNode* root, int k, vector<int>& ret)
	{
		if (root == nullptr || ed[root] == 1 || root->val == -1) return;
		ed[root] = 1;
		if (k == 0)
		{
			ret.push_back(root->val);
			return;
		}
		bfs(root->left, k - 1, ret);
		bfs(root->right, k - 1, ret);
		bfs(m[root], k - 1, ret);
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		TreeNode* tmp = new TreeNode(-1);
		inOrder(root, tmp, target);
		vector<int> ret;
		bfs(tar, k, ret);
		return ret;
	}
};