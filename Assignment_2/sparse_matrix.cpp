#include<iostream>
using namespace std;

int main(){
    int a[10][10];
    int n,m;
    cout<<"Enter the dinmension of matrix as row and coulmn"<<endl;
    cin>>n>>m;
    cout<<"enter the elements of matrix :"<<endl;
    for(int i=0; i<n;i++){
        for(int j=0 ;j<m ;j++){
            cin>>a[i][j];
        }
    }

    //counting non zero elements
    int count =0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ;j++){
            if(a[i][j] != 0){
                count++;
            }
        }
    }

    // creating a sparse matrix
    int row =0;
    int sp[count][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] !=0){
                sp[row][0] =i;
                sp[row][1] =j;
                sp[row][2] =a[i][j];
                row++;
            }
        }
    }

    //printng sparse matrix 
    cout<<"sparse matrix is : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0 ; j<3 ;j++){
            cout<<sp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
