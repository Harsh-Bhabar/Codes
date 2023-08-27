#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n and nums[left] > nums[largest])
	{
		largest = left;
	}
	if (right < n and nums[right] > nums[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(nums[largest], nums[i]);
		heapify(nums, n, largest);
	}
}
void print(vector<int> &nums)
{
	for (auto i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums = {4, 5, 1, 34, 6};
	for (int i = nums.size() / 2; i >= 0; i--)
	{ // n/2+1 -- n will be leaf nodes
		heapify(nums, nums.size(), i);
		print(nums);
	}
}