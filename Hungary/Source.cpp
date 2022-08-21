#include <queue>
#include <set>
#include <iostream>
using namespace std;
const int MAX = 100;
const int maxC = 10001;
int c[MAX][MAX];
int Fx[MAX], Fy[MAX], matchX[MAX], matchY[MAX], Trace[MAX];
int m, n, k, start, finish;
//đường mở sẽ bắt đầu từ start thuộc X và finish thuộc Y
void Enter()
{
	int i, j;
	cin >> m >> n;
	k = m > n ? m : n;//tìm số đỉnh nhiều nhất trong 2 bên X và Y
	//gán tất cả các cạnh là giá trị maxC ( rất lớn)
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			c[i][j] = maxC;
		}
	}
	
	// gán lại các giá trị c[i][j] đã có trọng số
	do
	{
		cin >> i >> j;
		if (i != -1)
			cin >> c[i - 1][j - 1];
	} while (i != -1);
}
void Init()
{
	int i, j;
	//Khởi tạo ban đầu 2 bộ ghép đều rỗng (các giá trị được gán bằng -1 nghĩa là chưa có
	// đỉnh X gán với Y hoặc ngược lại)
	memset(matchX, -1, sizeof(matchX));
	memset(matchY, -1, sizeof(matchY));
	//tìm trọng số nhỏ nhất của các cạnh liên thuộc với X[i]
	for (i = 0; i < k; i++)
	{
		Fx[i] = maxC;
		for (j = 0; j < k; j++)
		{
			if (c[i][j] < Fx[i])
			{
				Fx[i] = c[i][j];
			}
		}
	}
	//tìm trọng số nhỏ nhất của các cạnh liên thuộc với Y[j]
	for (j = 0; j < k; j++)
	{
		Fy[j] = maxC;
		for (i = 0; i < k; i++)
		{
			if (c[i][j] - Fx[i] < Fy[j])
			{
				Fy[j] = c[i][j] - Fx[i];
			}
		}
	}
}
//hàm cho biết trọng số cạnh {X[i], Y[j]}
int GetC(int i, int j)
{
	return c[i][j] - Fx[i] - Fy[j];
}
//tìm đường mở bắt đầu ở start
void FindAugmentingPath()
{
	queue<int> q;
	int i, j, first, last;

	memset(Trace, -1, sizeof(Trace));
	
	//chạy thuật toán BFS để tìm đường mở
	q.push(start);
	first = 0;
	last = 0;
	do
	{
		i = q.front();
		q.pop();
		//cout << "Dinh i la: " << i << endl;
		for (j = 0; j < k; j++)
		{
			//cout << "Get[" << i << "][" << j << "] = " << GetC(i, j) << endl;
			//cout << "Trace[" << j << "]" << Trace[j] << endl;
			if (Trace[j] == -1 && GetC(i, j) == 0)
			{
				Trace[j] = i;
				if (matchY[j] == -1)
				{
					finish = j;
					return;
				}
				q.push(matchY[j]);
			}	
		}
	} while (!q.empty());
}
//Xoay các trọng số cạnh
void SubX_AddY()
{
	int i, j, t, Delta;
	set<int> VisitedX, VisitedY;
	/*
	Để ý rằng:
	VisitedY = {y \ Trace[y] khác -1}
	VisitedX = {start} giao match(VisitedY) = {start} giao {matchY[y] Trace[y] khác -1}
	*/
	VisitedX.insert(start);
	for (j = 0; j < k; j++)
	{
		if (Trace[j] != -1)
		{
			VisitedX.insert(matchY[j]);
			VisitedY.insert(j);
		}
	}
	//Sau khi tìm được VisitedX và VisitedY, ta tìm delta là trọng số 
	// nhỏ nhất của cạnh nối từ VisitedX ra Y\VisitedY
	Delta = maxC;
	for (i = 0; i < k; i++)
	{
		if (VisitedX.find(i) != VisitedX.end())
		{
			for (j = 0; j < k; j++)
			{
				if ((VisitedY.find(j) == VisitedY.end()) && (GetC(i, j) < Delta))
					Delta = GetC(i, j);
			}
		}
	}
	//xoay trọng số cạnh
	for (t = 0; t < k; t++)
	{
		//trừ trọng số những cạnh liên thuộc với VisitedX đi Delta
		if (VisitedX.find(t) != VisitedX.end())
			Fx[t] = Fx[t] + Delta;
		//Cộng trọng số những cạnh liên thuộc với VisitedY lên Delta
		if (VisitedY.find(t) != VisitedY.end())
			Fy[t] = Fy[t] - Delta;
	}
}

//nới rộng bộ ghép bởi đường mở tìm được
void Enlarge()
{
	int x, next;
	do
	{
		x = Trace[finish];
		next = matchX[x];
		matchX[x] = finish;
		matchY[finish] = x;
		finish = next;
	} while (finish != -1);
}
//chạy thuật toán hungary
void Solve()
{
	int x, y;
	for (x = 0; x < k; x++)
	{
		//khởi tạo điểm bắt đầu và kết thúc của 1 đường mở
		//finish = -1 nghĩa là chưa tìm thấy đường mở
		start = x;
		finish = -1;
		do
		{
			FindAugmentingPath(); // tìm đường mở
			if (finish == -1) // nếu ko tìm được đường mở thì xoay các trọng số cạnh
				SubX_AddY();
		} while (finish == -1);
		Enlarge();//tăng cặp dựa trên đường mở tìm được
	}
}
int main()
{
	
	Enter();
	Init();
	Solve();
	cout << n - m << endl;
	int cost = 0;
	for (int x = 0; x < m; x++)
	{
		int y = matchX[x];
		///if (c[x][y] < maxC)
		//{
			cout << "X[" << x + 1 << "]-" << "Y[" << y + 1 << "] = " << c[x][y] << endl;
			cost += c[x][y];
		//}
	}
	cout << cost;
	return 0;
}