#pragma once
#include <vector>
using namespace std;

#define INF 99999999
//��С������
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
int closest[MAXN], lowcost[MAXN], m;//mΪ�ڵ�ĸ���
int G[MAXN][MAXN];//�ڽӾ���
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
	closest[0] = -1;//�����һ���㣬-1��ʾ�õ��ڼ���U�У������ڼ���V��
	int num = 0, ans = 0, e = 0;//eΪ���¼��뼯�ϵĵ�
	while (num < m - 1)//����m-1����
	{
		int micost = INF, miedge = -1;
		for (int i = 0; i < m; i++)
			if (closest[i] != -1)		//����ڼ���V��
			{
				int temp = G[e][i];
				if (temp < lowcost[i])	//��������߸�С�����lowcost
				{
					lowcost[i] = temp;
					closest[i] = e;		//����·��
				}
				if (lowcost[i] < micost)//������̳���0
					micost = lowcost[miedge = i];
			}
		ans += micost;
		closest[e = miedge] = -1;
		num++;
	}
	return ans;
}