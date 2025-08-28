#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, num;  
    Element *data;

   
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        num = n;
        data = new Element[n];
    }

    
    ~SparseMatrix() {
        delete[] data;
    }

    
    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < num; i++) {
            cout << data[i].row << "   " << data[i].col << "   " << data[i].val << endl;
        }
    }
};

// (a) Transpose
SparseMatrix transpose(SparseMatrix &m) {
    SparseMatrix t(m.cols, m.rows, m.num);
    int k = 0;
    for (int c = 0; c < m.cols; c++) {
        for (int i = 0; i < m.num; i++) {
            if (m.data[i].col == c) {
                t.data[k].row = m.data[i].col;
                t.data[k].col = m.data[i].row;
                t.data[k].val = m.data[i].val;
                k++;
            }
        }
    }
    return t;
}

// (b) Addition
SparseMatrix add(SparseMatrix &a, SparseMatrix &b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added!\n";
        return SparseMatrix(0, 0, 0);
    }

    SparseMatrix sum(a.rows, a.cols, a.num + b.num);
    int i = 0, j = 0, k = 0;

    while (i < a.num && j < b.num) {
        if (a.data[i].row < b.data[j].row ||
            (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        }
        else if (b.data[j].row < a.data[i].row ||
                 (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            sum.data[k++] = b.data[j++];
        }
        else {
            sum.data[k] = a.data[i];
            sum.data[k++].val = a.data[i++].val + b.data[j++].val;
        }
    }
    while (i < a.num) sum.data[k++] = a.data[i++];
    while (j < b.num) sum.data[k++] = b.data[j++];

    sum.num = k;
    return sum;
}

// (c) Multiplication
SparseMatrix multiply(SparseMatrix &a, SparseMatrix &b) {
    if (a.cols != b.rows) {
        cout << "Matrices cannot be multiplied!\n";
        return SparseMatrix(0, 0, 0);
    }

  
    SparseMatrix bt = transpose(b);

    SparseMatrix result(a.rows, b.cols, a.num * b.num); // max possible size
    int k = 0;

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int p = 0; p < a.num; p++) {
                if (a.data[p].row == i) {
                    for (int q = 0; q < bt.num; q++) {
                        if (bt.data[q].row == j && bt.data[q].col == a.data[p].col) {
                            sum += a.data[p].val * bt.data[q].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                result.data[k++] = {i, j, sum};
            }
        }
    }
    result.num = k;
    return result;
}


int main() {
    
    SparseMatrix A(3, 3, 3);
    A.data[0] = {0, 0, 5};
    A.data[1] = {1, 1, 8};
    A.data[2] = {2, 2, 3};

    
    SparseMatrix B(3, 3, 3);
    B.data[0] = {0, 1, 6};
    B.data[1] = {1, 1, 7};
    B.data[2] = {2, 0, 4};

    cout << "Matrix A:\n"; A.display();
    cout << "\nMatrix B:\n"; B.display();

    cout << "\nTranspose of A:\n";
    SparseMatrix T = transpose(A);
    T.display();

    cout << "\nA + B:\n";
    SparseMatrix S = add(A, B);
    S.display();

    cout << "\nA * B:\n";
    SparseMatrix M = multiply(A, B);
    M.display();

    return 0;
}
