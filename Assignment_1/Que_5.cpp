#include<iostream>
using namespace std;

void inputMatrix(int arr[][10], int rows, int colmns) {
    cout << "Enter elements of the matrix:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colmns; j++) {
            cin >> arr[i][j];
        }
    }
}

void displayMatrix(int arr[][10], int rows, int colmns) {
    cout << "Matrix:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colmns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sumRows(int arr[][10], int rows, int colmns) {
    cout << "Sum of each row:"<<endl;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < colmns; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }
}

void sumColmns(int arr[][10], int rows, int colmns) {
    cout << "Sum of each column: "<<endl;
    for (int j = 0; j < colmns; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }
}

int main(){

    int rows , colmns;
    int arr[10][10];

    cout << "Enter number of rows: "<<endl;
    cin >> rows;
    cout << "Enter number of columns: "<<endl;
    cin >> colmns;

    inputMatrix(arr, rows, colmns);
    displayMatrix(arr, rows, colmns);
    sumRows(arr, rows, colmns);
    sumColmns(arr, rows, colmns);

    return 0;
}

