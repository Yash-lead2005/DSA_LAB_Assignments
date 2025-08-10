#include<iostream>
using namespace std;

// making a global array 
int *arr = nullptr; // dynamic array to take size as input 
int n =0;


void createArray(){
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elememts of array "<<endl;

    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }
}


void display(){
    cout<<"Array elements are : "<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}



void insertion(){
    int pos , val;
    cout<<"Enter the position to add new element"<<endl;
    cin>>pos;
    cout<<"Enter the value of new element"<<endl;
    cin>>val;

    int *newArr = new int[n+1];
    for(int i=0 ; i<pos-1 ; i++){
        newArr[i] = arr[i];
    }
    newArr[pos-1] = val;

    for(int i = pos; i<=n ; i++){
        newArr[i] = arr[i-1];
    }

    arr = newArr;
    n++;
}


void deletion(){
    int pos , val;
    cout<<"Enter the position to delete  element"<<endl;
    cin>>pos;
    
    int *newArr = new int[n-1];
    for(int i=0 ; i<pos-1 ; i++){
        newArr[i] = arr[i];
    }
    for(int i=pos; i<=n ; i++){
        newArr[i-1] = arr[i];
    }

    arr = newArr;
    n--;
}


void linearsearch(){
    int val;
    cout<<"Enter the value to search"<<endl;
    cin>>val;

    for(int i =0 ; i<n ; i++){
        if(arr[i] == val){
            cout<<"Element is found at index "<< i<<endl;
        }
        else{
             cout<<"element not found"<<endl;
        }
    }
}


int main(){

    cout<<"MAKING A MENU "<<endl;
    cout<<"1. CREATE FUNCTION "<<endl;
    createArray();
    display();

    cout<<"INSERTION"<<endl;
    insertion();
    display();

    cout<<"DELETION"<<endl;
    deletion();
    display();

    cout<<"LINEAR SEARCH "<<endl;
    linearsearch();


    cout<<"EXIT";

    return 0;

}
