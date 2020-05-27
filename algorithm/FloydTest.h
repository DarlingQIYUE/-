#pragma once
#include <vector>
#include <iostream>
using namespace std;

//多源最短路径
vector<vector<int>> Floyd(vector<vector<int>> matrix) {
	vector<vector<int>> m = matrix;
	vector<vector<int>> s(matrix.size(),vector<int>(matrix.size()));
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (i != j)s[i][j] = j;
			else s[i][j] = -1;
		}
	}
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			for (int k = 0; k < m.size(); k++) {
				if (m[j][k] > m[j][i] + m[i][k]) {
					m[j][k] = m[j][i] + m[i][k];
					s[j][k] = i;
				}
			}
		}
	}
	return s;
}


