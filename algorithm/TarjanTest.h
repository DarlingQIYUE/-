#pragma once
//求连通图中强连通图的算法
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

stack<int> s;
vector<int> dfn;
vector<int> low;
vector<bool> in_stack;

int time = 1;

void Tarjan_DFS(vector<vector<int>> &matrix, int x) {
	s.push(x);
	in_stack[x] = true;
	dfn[x] = low[x] = time++;
	for (int y = 0; y < matrix.size(); y++) {
		if (matrix[x][y] == 1) {
			if (dfn[y] == 0) {		//未被访问过
				Tarjan_DFS(matrix,y);		//递归
				low[x] = min(low[x],low[y]);	//在所有已确定节点中找到最小值
			}
			else if (in_stack[x] == true) {		//在栈中存在
				low[x] = min(low[x], low[y]);	//在栈中
			}
		}
	}
	if (dfn[x] == low[x]) {
		int tmp;
		do{
			tmp = s.top(); 
			s.pop();
			in_stack[tmp] = false;
			cout << tmp << "-";
		} while (tmp != x);
		cout << endl;
	}
}

vector<int> Tarjan(vector<vector<int>> &matrix) {
	dfn = vector<int>(matrix.size(), 0);
	low = vector<int>(matrix.size(), 0);
	in_stack = vector<bool>(matrix.size(), false);
	Tarjan_DFS(matrix, 0);
	return conset;
}