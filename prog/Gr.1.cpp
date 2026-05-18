#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> Gr;
int n;

void find(int v) {
	vector<int> u(n, 0);
	u[v] = 1;
	for (int i = 0; i < Gr[v].size(); i++) {
		int neighbor = Gr[v][i];
		u[neighbor] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (u[i] == 0)
			cout << i << " ";
	}
	cout << endl;
}

