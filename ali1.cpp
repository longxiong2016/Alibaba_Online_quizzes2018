#include<iostream>
#include<vector>
using namespace std;

int GetMincost(int **cost,int N,int K)
{
	int *pathcost = new int[K];

	for (int i = 0; i < K; ++i)
	{
		pathcost[i] = cost[0][i];
		int precolor = i;

		for (int j = 1; j < N; ++j)
		{
			int mincostcolor = INT_MAX;
			for (int k = 0; k < K; ++k)
			{
				if (k != precolor&&cost[j][k] < mincostcolor)
				{
					mincostcolor = cost[j][k];
					precolor = k;
				}
			}
			pathcost[i] += mincostcolor;
		}
	}

	int mincostpath = INT_MAX;
	for (int i = 0; i < K; ++i)
		if (pathcost[i] < mincostpath)
			mincostpath = pathcost[i];
	return mincostpath;
}

int main()
{
	int N,K;
	cin >> N >> K;
	int **cost;
	cost = new int *[N];
	for (int i = 0; i < N; ++i)
		cost[i] = new int[K];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < K; ++j)
			cin>>cost[i][j];

	cout << GetMincost(cost,N,K) << endl;

	for (int i = 0; i < N; ++i)
		delete [] cost[i];
	delete []cost;
	return 0;
}
