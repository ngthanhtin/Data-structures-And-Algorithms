#include <iostream>
using namespace std;
#define MAX 1000
int BIT[MAX];
int a[MAX];
int n;

void update(int x, int val)
{
	for (; x <= n; x += x&-x)
		BIT[x] += val;
}

int query(int x)
{
	int sum = 0;
	for (; x > 0; x -= x&-x)
		sum += BIT[x];
	return sum;
}

int main()
{
	cin >> n; // the number of elements in array a
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i, a[i]);
	}
	cout << "Sum of first 10 elements is: " << query(10) << endl;
	int sum2 = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum2 += a[i];
	}
	cout << "Sum of first 10 elements is (traditional method): " << sum2 << endl;
	cout << "Sum of all elements in range [2,7] is: " << query(7) - query(2 - 1) << endl;
	return 0;
}