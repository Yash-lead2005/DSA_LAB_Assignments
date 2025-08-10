#include<iostream>
using namespace std;


void reverseArr(int arr[] , int &n){
    int i =0;
    int j = n-1;
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    cout<<endl;
}

void multiplyMatrix(int a[][10], int b[][10], int result[][10], int r1, int c1, int r2, int c2 ){

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout<< "Result of Matrix Multiplication:"<<endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout<< result[i][j] << " ";
        }
        cout<< endl;
    }
}



void transposeMatrix(int a[][10] , int r1, int c1){

    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}




int main(){
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }


    reverseArr(arr , n);
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }



    int r1,r2,c1,c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    int a[10][10];
    cout << "Enter elements of first matrix:"<<endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cin >> a[i][j];
        }
    }


    cout << "Enter rows and columns for second matrix: "<<endl;
    cin >> r2 >> c2;
    int b[10][10];
    cout << "Enter elements of second matrix:"<<endl;
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cin >> b[i][j];
        }
    }


    int res[10][10];

    cout<<"Multiplication of Arrays : "<<endl;
    multiplyMatrix(a,b,res,r1,r2,c1,c2);

    cout << "Transpose of first matrix:"<<endl;
    transposeMatrix(a, r1, c1);

    return 0;
}
