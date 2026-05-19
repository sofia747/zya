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
