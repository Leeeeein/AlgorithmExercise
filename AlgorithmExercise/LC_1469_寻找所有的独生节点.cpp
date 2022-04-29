#include "SolutionBaseClass.cpp"

class LC_1469 : public Solution
{
public:
	vector<int> getLonelyNodes(TreeNode* root) {
		vector<int> ret;
		helper(root, ret, false);
		return ret;
	}
	void helper(TreeNode* root, vector<int>& ret, bool flag)
	{
		if (root == nullptr)
			return;
		if (flag == true)
			ret.push_back(root->val);
		if (root->left != nullptr && root->right != nullptr)
		{
			helper(root->left, ret, false);
			helper(root->right, ret, false);
			return;
		}
		helper(root->left, ret, true);
		helper(root->right, ret, true);

	}
};