#include<iostream>
using namespace std;

int binarysearch(int arr[] , int n , int target){

     int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] > target) {
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    return -1; 
}




int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to fond"<<endl;
    cin>>target;
    int result = binarysearch(arr, n ,target );
    cout<<result;
    return 0;
}

