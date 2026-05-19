#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;
    cout << n << "! = " << factorial(n) << endl;
    return 0;
}