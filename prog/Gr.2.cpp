//Дан ориентированный граф. Вставить в граф ребро, соединяющее вершины A и B.
#include<iostream>
#include<vector>
#include<locale>
using namespace std;

vector<vector<int>> Gr;
int n;

void add(int a, int b) {
	if (a < 0 || a >= n || b < 0 || b >= n) {
		cout << "таких вершин не существует" << endl;
		return;
	}
		
	Gr[a].push_back(b);
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << i << " -> ";
		for (int j = 0; j < Gr[i].size(); j++)
			cout << Gr[i][j] << " ";
		cout << "| ∅" << endl;
	}
}
int main() {
	setlocale(LC_ALL, "RUS");
	cout << "кол-во вершин = "; cin >> n;
	Gr.resize(n);
	
	int m;
	cout << "кол-во ребер = "; cin >> m;
	
	if (m) {
		cout << "ребра " << endl;
		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			if (x < 0 || x >= n || y < 0 || y >= n) {
				continue;
			}
			Gr[x].push_back(y);
		}
	}else cout << "граф пустой " << endl;

	print();
	int a, b;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	add(a, b);
	print();
	return 0;
}