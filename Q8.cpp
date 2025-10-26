#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 4, 5, 2, 3, 1, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int hash[1000] = {0};

    int distinct = 0;
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 0) {
            hash[arr[i]] = 1;
            distinct++;
        }
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Total distinct elements: " << distinct << endl;
    return 0;
}
