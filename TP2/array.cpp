#include <iostream>
using namespace std;

int main(){
    //deklarasi arr dan arr2
    int arr[10];
    int arr2[10];

    //input arr
    cout<<"input elemen pada array 1 : ";
    for (int i = 0 ; i < sizeof(arr)/sizeof(int) ; i++){
        cin>>arr[i];
    }

    //input arr2
    cout<<"input elemen pada array 2 : ";
    for (int i = 0 ; i < sizeof(arr2)/sizeof(int) ; i++){
        cin>>arr2[i];
    }

    //loop penambahan setiap elemen pada 2 array
    cout<<"jumlah elemen tiap array : ";
    for(int i = 0 ; i < 10 ; i++){
        cout<<arr[i] + arr2[i]<< " ";
    } 

    return 0 ;
}
