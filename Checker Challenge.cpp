#include <bits/stdc++.h>
using namespace std;
int n, m1[30] = {0}, m2[30] = {0}, m3[30] = {0}, ans[15] = {0}, mark = 0;//要有棋盘数量，三种方向的标记，存放的位置，解法数量
void setvalue(int x, int y, int k)//存储皇后放置的位置，以及标记列，顺斜线，逆斜线
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
		mark++;//解法数量
		if(mark <= 3)//按题目要求
		{
			for(int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << endl;
		}
		return;
	}
	for(int j = 1; j <= n; j ++)
	{
		if(m1[j] || m2[step+j] || m3[step-j+n]) continue;//如果不能放置，去下一格
		setvalue(step, j, 1);//传入行，列，要改变的标记
		dfs(step+1);//进入下一行
		setvalue(step, j, 0);//到这一步，代表这一格不能放置，取消标记
		
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << mark;
	return 0;
}
