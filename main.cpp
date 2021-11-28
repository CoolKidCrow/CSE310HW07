#include <iostream>
using namespace std;

int main() {
    int** arr;
    int n, m, row, col;
    cin >> n >> m;

    arr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> row >> col;
        arr[row][col] = 1;
        arr[col][row] = 1;
    }

    cout << n << " " << m << "\n";

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }


    for(int i = 0; i <= n;i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}