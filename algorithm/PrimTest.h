#pragma once
#include <vector>
using namespace std;

#define INF 99999999
//最小生成树
vector<pair<int, int>> Prim(vector<vector<int>>matrix) {
	int n = matrix.size();
	vector<int>vis(n, 0);
	vector<pair<int, int>>s;
	vis[0] = 1;
	for (int k = 0; k < n; k++) {
		int min = INF;
		int minf = -1, mins = -1;
		for (int i = 0; i < n; i++) {
			if (vis[i] == 1) {
				for (int j = 0; j < n; j++) {
					if (vis[j] == 0 && matrix[i][j] < min) {
						min = matrix[i][j];
						minf = i;
						mins = j;
					}
				}
			}
		}
		if (mins == -1) {
			return s;
		}
		else {
			s.push_back(make_pair(minf, mins));
			vis[mins] = 1;
		}
	}
}


#define MAXN 1000
#define INF 1 << 30
int closest[MAXN], lowcost[MAXN], m;//m为节点的个数
int G[MAXN][MAXN];//邻接矩阵
int prim()
{
	for (int i = 0; i < m; i++)
	{
		lowcost[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		closest[i] = 0;
	}
	closest[0] = -1;//加入第一个点，-1表示该点在集合U中，否则在集合V中
	int num = 0, ans = 0, e = 0;//e为最新加入集合的点
	while (num < m - 1)//加入m-1条边
	{
		int micost = INF, miedge = -1;
		for (int i = 0; i < m; i++)
			if (closest[i] != -1)		//如果在集合V中
			{
				int temp = G[e][i];
				if (temp < lowcost[i])	//如果这条边更小则更新lowcost
				{
					lowcost[i] = temp;
					closest[i] = e;		//更新路径
				}
				if (lowcost[i] < micost)//更新最短长度0
					micost = lowcost[miedge = i];
			}
		ans += micost;
		closest[e = miedge] = -1;
		num++;
	}
	return ans;
}