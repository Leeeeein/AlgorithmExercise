#include "SolutionBaseClass.cpp"

class LC_215 : public Solution
{
public:
	int quickSort(vector<int>& nums, int left, int right)
	{
		int pivot = left + (right - left) / 2;
		int m = nums[pivot];
		while (left < right)
		{
			while (nums[right] <= m && left < right)
			{
				right--;
			}
			nums[left] = nums[right];
			while (nums[left] >= m && left < right)
			{
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = m;
		return left;
	}

	int search(vector<int>& nums, int left, int right, int k)
	{
		int rval = quickSort(nums, left, right);
		if (rval == k - 1)
		{
			return rval;
		}
		else if (rval > k - 1)
		{
			return search(nums, left, rval - 1, k);
		}
		else
		{
			return search(nums, rval + 1, right, k - rval);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		return search(nums, 0, nums.size() - 1, k);
	}
};