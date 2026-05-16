#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Введите количество строк треугольника Паскаля: ";
    cin >> n;
    
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    