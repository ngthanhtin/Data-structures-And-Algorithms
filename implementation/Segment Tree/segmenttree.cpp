#include <iostream>
using namespace std;
const int MAX = 100001;
int tree[MAX];
int A[MAX];
//build segment tree in which the father node will be the sum of its children nodes.
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
//
void update(int node, int start, int end, int idx, int val)
{
	if (start == end)
	{
		//leaf node
		//add A[idx] and tree[node] by val
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
//Query
/*
1.If the range represented by a node is completely outside the given range,
  simply return 0
2. the range represented by a node is completely within the given range,
   return the value of the node which is the sum of all the elements in the range represented by the node
3.And if the range represented by a node is partially inside and partially outside the given range,
  return sum of the left child and the right child
*/
int querySum(int node, int start, int end, int l, int r)
{
	if (r < start || end < l)
	{
		//range represented by a node is completely outside the given range
		return 0;
	}
	if (l <= start && end <= r)
	{
		//range represented by a node is completely inside the given range
		return tree[node];
	}
	//range represented by a node is partially inside and partially outside the given range
	int mid = (start + end) / 2;
	int p1 = querySum(2 * node, start, mid, l, r);
	int p2 = querySum(2 * node + 1, mid + 1, end, l, r);
	return p1 + p2;
}
int main()
{
	
	return 0;
}