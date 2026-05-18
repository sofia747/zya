#include <iostream>
#include <vector>
using namespace std;

void printTriangle(const vector<vector<int>>& triangle) {
    int n = triangle.size();
    int maxNum = triangle[n-1][n-1/2];
    int maxWidth = to_string(maxNum).length();
    
    for (int i = 0; i < n; i++) {
        cout << string((n - i - 1) * (maxWidth + 1), ' ');
        
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << string(maxWidth + 1 - to_string(triangle[i][j]).length(), ' ');
        }
        cout << endl;
    }
}

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
cout << "\nТреугольник Паскаля:\n\n";
    printTriangle(triangle);
    
    return 0;
}
    