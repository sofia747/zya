//Дан неориентированный граф. Вывести на экран все вершины, не смежные с данной.
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

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "кол-во вершин n = "; cin >> n;
	Gr.resize(n);
	int m;
	cout << "кол-во ребер m = "; cin >> m;
	cout << "вводим ребра ";
	for (int j = 0; j < m; j++) {
		int x, y;
		cin >> x >> y;

		Gr[x].push_back(y);
		Gr[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cout << i << " -> ";
		for (int j = 0; j < Gr[i].size(); j++) {
			cout << Gr[i][j] << " ";
		}
		cout << "| ∅" << endl;
	}
	cout << "номер вершины ";
	int v;
	cout << "v = "; cin >> v;
	if (v < 0 || v >= n) {
		return 1;
	}
	find(v);
	return 0;
}