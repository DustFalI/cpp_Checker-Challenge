#include <bits/stdc++.h>
using namespace std;
int n, m1[30] = {0}, m2[30] = {0}, m3[30] = {0}, ans[15] = {0}, mark = 0;
void setvalue(int x, int y, int k)
{
	ans[x] = y;
	m1[y] = k;
	m2[x+y] = k;
	m3[x-y+n] = k;
}
void dfs(int step)
{
	if(step > n)
	{
		mark++;
		if(mark <= 3)
		{
			for(int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << endl;
		}
		return;
	}
	for(int j = 1; j <= n; j ++)
	{
		if(m1[j] || m2[step+j] || m3[step-j+n]) continue;
		setvalue(step, j, 1);
		dfs(step+1);
		setvalue(step, j, 0);
		
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << mark;
	return 0;
}
