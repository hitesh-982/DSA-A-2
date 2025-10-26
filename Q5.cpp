#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of matrix (n x n): ";
    cin >> n;

    cout << "Space requirements:" << endl;
    cout << "(a) Diagonal Matrix: " << n << endl;
    cout << "(b) Tri-diagonal Matrix: " << 3 * n - 2 << endl;
    cout << "(c) Lower Triangular Matrix: " << n * (n + 1) / 2 << endl;
    cout << "(d) Upper Triangular Matrix: " << n * (n + 1) / 2 << endl;
    cout << "(e) Symmetric Matrix: " << n * (n + 1) / 2 << endl;
    return 0;
}
