#include <iostream>
using namespace std;
const int MAX = 100;
int tree[MAX];
int A[MAX];
void build(int node, int start, int end)
{
	if (start == end)
	{
		// leaf node will have a single element
		tree[node] = A[start];
	}
	else
	{
		int mid = (start + end) / 2;
		//recurse on the left child
		build(2 * node, start, mid);
		//recurse on the right child
		build(2 * node + 1, mid + 1, end);
		//internal node will have the sum of both of its children
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
void update(int node, int start, int end, int idx, int val)
{
	if (start == end)
	{
		//leaf node
		A[idx] += val;
		tree[node] += val;
	}
	else
	{
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid)
		{
			//if idx is in the leaf child, recurse on the leaf child
			update(2 * node, start, mid, idx, val);
		}
		else
		{
			//if idx is in the right child, recurse on the right child
			update(2 * node + 1, mid + 1, end, idx, val);
		}
		//internal node will have the sum of both of its children
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
int main()
{
	return 0;
}