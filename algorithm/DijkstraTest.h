#pragma once
#include <vector>

#define INF 99999999	//���������
//��Դ���·��
//matrix�ڽӾ���  sԴ��
vector<int> Dijkstra(vector<vector<int>> matrix,int s) {
	int n = matrix.size();		//�ڵ�����
	vector<int> dis(n,INF);		//distance��¼���·�����ȣ���ʼֵ�����
	vector<int> par(n,-1);		//parent��¼·������ʼֵ-1
	vector<int> vis(n,0);		//visited��¼�Ƿ���ʹ�����ʼֵΪfalse

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
