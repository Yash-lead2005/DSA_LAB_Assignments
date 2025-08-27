#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the elements of the array"<<endl;
    for(int i=0 ; i< n ; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the target sum to find in array "<<endl;
    cin>>k;

    for(int i= 0; i< n ; i++){
        for(int j=i+1; j<n ; j++){
            if(abs(arr[i] - arr[j]) ==k  ){
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    return 0;

}

