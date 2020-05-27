#include <iostream>
#include <vector>
#include "DijkstraTest.h"
#include "FloydTest.h"
#include "PrimTest.h"
#include "KruskalTest.h"
using namespace std;

#define INF 99999999	//定义无穷大

int main() {
	//dijkstra时为初始值INF
	//Floyd时初始值为0
	vector<vector<int>> matrix(5, vector<int>(5, -1));
	matrix[0][1] = 6; matrix[1][0] = 6;
	matrix[0][3] = 1; matrix[3][0] = 1;
	matrix[1][2] = 5; matrix[2][1] = 5;
	matrix[1][3] = 2; matrix[3][1] = 2;
	matrix[1][4] = 2; matrix[4][1] = 2;
	matrix[3][4] = 1; matrix[4][3] = 1;
	matrix[2][4] = 5; matrix[4][2] = 5;

	for (vector<int> v : matrix) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}

	//vector<int> par = Dijkstra(matrix, 4);

	//for (int i : par) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//vector<vector<int>> s = Floyd(matrix);

	//for (vector<int> ss : s) {
	//	for (int i : ss) {
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//}

	//vector<pair<int, int>> s = Prim(matrix);

	//for (pair<int,int> p : s) {
	//	cout << p.first << " " << p.second << endl;
	//}

	vector<Node> p;
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			if (matrix[i][j] > 0) {
				p.push_back(Node{ matrix[i][j],i,j });
			}
		}
	}
	Kruskal(matrix, p);



	return 0;
}