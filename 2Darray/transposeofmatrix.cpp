#include <iostream>
using namespace std;

void print_array(int arr[][3], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = m-1; j >=0; j--) { //for rotating 90 degree;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(int arr[][3], int m, int n) {
    int transposemat[3][3]={{0}};
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            transposemat[j][i] = arr[i][j];
        }
    }
   print_array(transposemat,3,3);
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    transpose(arr, 3, 3);
    return 0;
}
