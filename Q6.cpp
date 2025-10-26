#include <iostream>
using namespace std;


struct Term {
    int row;
    int col;
    int val;
};


void createTriplet(int mat[10][10], int r, int c, Term triplet[]) {
    int k = 1;
    triplet[0].row = r;
    triplet[0].col = c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].val = mat[i][j];
                k++;
            }
        }
    }
    triplet[0].val = k - 1;
}


void displayTriplet(Term t[]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= t[0].val; i++)
        cout << t[i].row << "\t" << t[i].col << "\t" << t[i].val << endl;
}


void transpose(Term a[], Term b[]) {
    int n = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}


void addSparse(Term a[], Term b[], Term sum[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible!" << endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            sum[k].row = a[i].row;
            sum[k].col = a[i].col;
            sum[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if (a[i].row < b[j].row || 
                  (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else {
            sum[k++] = b[j++];
        }
    }
    while (i <= a[0].val) sum[k++] = a[i++];
    while (j <= b[0].val) sum[k++] = b[j++];
    sum[0].val = k - 1;
}


void multiplySparse(Term a[], Term b[], Term result[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible!" << endl;
        return;
    }

    Term bt[50];
    transpose(b, bt);

    result[0].row = a[0].row;
    result[0].col = b[0].col;
    int k = 1;

    for (int i = 0; i < a[0].row; i++) {
        for (int j = 0; j < b[0].col; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0].val; x++) {
                if (a[x].row != i) continue;
                for (int y = 1; y <= bt[0].val; y++) {
                    if (bt[y].row != j) continue;
                    if (a[x].col == bt[y].col)
                        sum += a[x].val * bt[y].val;
                }
            }
            if (sum != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].val = sum;
                k++;
            }
        }
    }
    result[0].val = k - 1;
}

int main() {
    int r1, c1, r2, c2;
    int A[10][10], B[10][10];

    cout << "Enter rows and cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    Term T1[50], T2[50], Tsum[50], Tmul[50], Ttrans[50];

    createTriplet(A, r1, c1, T1);
    createTriplet(B, r2, c2, T2);

    cout << "\nTriplet form of Matrix A:";
    displayTriplet(T1);
    cout << "\nTriplet form of Matrix B:";
    displayTriplet(T2);

    // (a) Transpose
    transpose(T1, Ttrans);
    cout << "\n(a) Transpose of A:";
    displayTriplet(Ttrans);

    // (b) Addition
    cout << "\n(b) Addition (A + B):";
    addSparse(T1, T2, Tsum);
    displayTriplet(Tsum);

    // (c) Multiplication
    cout << "\n(c) Multiplication (A x B):";
    multiplySparse(T1, T2, Tmul);
    displayTriplet(Tmul);

    return 0;
}
