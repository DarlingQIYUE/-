#pragma once
#include <vector>
using namespace std;

#define INF 99999999	//定义无穷大
//单源最短路径
//matrix邻接矩阵  s源点
vector<int> Dijkstra(vector<vector<int>> matrix,int s) {
	int n = matrix.size();		//节点总数
	vector<int> dis(n,INF);		//distance记录最短路径长度，初始值无穷大，
	vector<int> par(n,-1);		//parent记录路径，初始值-1
	vector<int> vis(n,0);		//visited记录是否访问过，初始值为false

	dis[s] = 0;
	int k = s;
	for (int i = 0; i < n; i++) {
		vis[k] = 1;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 0 && dis[k] + matrix[k][j] < dis[j]) {
				dis[j] = dis[k] + matrix[k][j];
				par[j] = k;
			}
		}
		k = 0;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 0) {
				if (dis[j] < dis[k] || k == 0) {
					k = j;
				}
			}
		}
	}
	return par;
}
