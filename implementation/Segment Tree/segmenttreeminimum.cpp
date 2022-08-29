#include <iostream>
using namespace std;
const int MAX = 100001;
int tree[MAX];
int A[MAX];
// build minimum segment tree
void buildMinimum(int node, int start, int end)
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
		buildMinimum(2 * node, start, mid);
		//recurse on the right child
		buildMinimum(2 * node + 1, mid + 1, end);
		//internal node will have the minimum of both of its children
		tree[node] = (tree[2 * node] < tree[2 * node + 1]) ? tree[2 * node] : tree[2 * node + 1];

	}
}
//
void updateMinimum(int node, int start, int end, int idx, int val)
{
	if (start == end)
	{
		//leaf node
		//add A[idx] and tree[node] by val
		//A[idx] += val;
		//tree[node] += val;
		//update A[idx] and tree[node] as val
		A[idx] = val;
		tree[node] = val;
	}
	else
	{
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid)
		{
			//if idx is in the leaf child, recurse on the leaf child
			updateMinimum(2 * node, start, mid, idx, val);
		}
		else
		{
			//if idx is in the right child, recurse on the right child
			updateMinimum(2 * node + 1, mid + 1, end, idx, val);
		}
		//internal node will have the minimum of both of its children
		tree[node] = (tree[2 * node] < tree[2 * node + 1]) ? tree[2 * node] : tree[2 * node + 1];
	}
}
//Query
/*
1.If the range represented by a node is completely outside the given range,
simply return MAX
2. the range represented by a node is completely within the given range,
return the value of the node which is the the minimum of 
all the elements in the range represented by the node
3.And if the range represented by a node is partially inside and partially outside the given range,
return the minimum of the left child and the right child
*/
//query the minimum of an interval (l,r)
int queryMinimum(int node, int start, int end, int l, int r)
{
	if (r < start || end < l)
	{
		//range represented by a node is completely outside the given range
		return MAX;
	}
	if (l <= start && end <= r)
	{
		//range represented by a node is completely inside the given range
		return tree[node];
	}
	//range represented by a node is partially inside and partially outside the given range
	int mid = (start + end) / 2;
	int p1 = queryMinimum(2 * node, start, mid, l, r);
	int p2 = queryMinimum(2 * node + 1, mid + 1, end, l, r);
	//the smallest between two value
	return (p1 < p2) ? p1 : p2;
}
int main()
{
	int N, Q; //number of elements and number of queries
	cin >> N >> Q;
	// input array A
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	//build segment tree first
	int first_node = 1;
	buildMinimum(first_node, 1, N);
	char c;

	for (int i = 0; i < Q; i++)
	{
		cin >> c;
		if (c == 'q')
		{
			//find the minimum between an interval (left,right)
			int l, r;
			cin >> l >> r;
			int m = queryMinimum(first_node, 1, N, l, r);
			cout << m << endl;
		}
		else if (c == 'u')
		{
			//update A[x] = y
			int x, y;
			cin >> x >> y;
			updateMinimum(first_node, 1, N, x, y);
		}
	}
	return 0;
}