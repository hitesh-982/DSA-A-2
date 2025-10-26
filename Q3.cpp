#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i + 1] - arr[i] != 1)
            return arr[i] + 1;
    return -1;
}

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    int diff = arr[0] - 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] - mid != diff)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low + diff;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements (1 to n, one missing): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing number (Binary): " << findMissingBinary(arr, n) << endl;
    return 0;
}
