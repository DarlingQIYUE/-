#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int *arr;

struct Node {
	int cost;
	int s, t;
};
bool cmp(Node n1,Node n2) {
	return n1.cost < n2.cost;
}
void init(int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = -1;
	}
}
int myfind(int i) {
	if (arr[i] < 0) {
		return i;
	}
	return arr[i] = myfind(arr[i]);
}

void join(int i,int j) {
	int fa = myfind(i);
	int fb = myfind(j);
	int temp = arr[fa] + arr[fb];
	if (fa != fb) {
		if (fa < fb) {
			arr[fb] = fa;
			arr[fa] = temp;
		}
		else {
			arr[fa] = fb;
			arr[fb] = temp;
		}
	}
}
void Kruskal(vector<vector<int>> matrix,vector<Node> e) {
	sort(e.begin(), e.end(), cmp);
	int len = matrix.size();
	arr = new int[len];
	init(len);
	int num = 0;
	for (int i = 0; i < e.size(); i++) {
		int s = e[i].s;
		int t = e[i].t;
		if (myfind(s) != myfind(t)) {
			join(s, t);
			num++;
			cout << s << " " << t << endl;
		}
		if (num >= len - 1) {
			break;
		}
	}
}