// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums)
{
	for (auto i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

void addInPQ(vector<int> &nums, int num)
{
	cout << "INSERTING " << num << endl;
	nums.push_back(num); // added the element at end
	int n = nums.size(); // new length

	int i = n - 1;

	while (i > 0)
	{
		int parent = (i - 2) / 2;
		if (nums[parent] < nums[i])
		{
			swap(nums[parent], nums[i]);
			i = parent;
		}
		else
		{
			break;
		}
	}
	print(nums);
}

void deleteInPQ(vector<int> &nums)
{
	cout << "DELETING " << endl;
	int n = nums.size();
	if (n == 0)
	{
		return;
	}
	nums[0] = nums[n - 1];
	nums.pop_back();

	int i = 0;
	int largest = i;
	while (i < n)
	{
		int left = (2 * i) + 1;
		int right = (2 * i) + 2;

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
			i = largest;
		}
		else
		{
			break;
		}
	}
	print(nums);
}

int main()
{
	//     10
	//     /\
//     7 8
	//   /\ /\
//   4 5 6 3

	vector<int> nums = {};
	addInPQ(nums, 1);
	addInPQ(nums, 2);
	addInPQ(nums, 3);
	addInPQ(nums, 4);
	addInPQ(nums, 5);
	deleteInPQ(nums);
	addInPQ(nums, 5);
	addInPQ(nums, -5);
	addInPQ(nums, 56);
	// deleteInPQ(nums);

	return 0;
}