#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	if (N == 0)
		cout << 0;
	if (N == 1)
		cout << 3;
    N = N + 1;
	
	int S = 0;
	int SSS = N - 2;
	for (int i = 1; i <= N - 2; ++i)
	{
		S = S + SSS;
		SSS = SSS - 1;
	}
	S = S * 2 + 3;
	cout << S << endl;
	return 0;


}