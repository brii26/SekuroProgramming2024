#include <iostream>
using namespace std;
int main(){
    //deklarasi dan input variabel
    int num = 0;
    int n ; 
    cout<<"N : ";
    cin>>n;

    //loop untuk membuat pola awal
    for (int i = 0 ; i < n / 2 + 1 ; i++){
        for (int j = 0 ; j < i ; j++){
            cout<<" ";
        }
        for (int x = 0 ; x < ((n / 2 + 1) - i) ; x++){
            cout<<num;
            num = (num + 1) % 10;
        }
        cout<<endl;
    }

    //variabel basis sebagai syarat jika num genap atau ganjil
    int var;
    var = ((n % 2  == 0) ? 1 : 0);

    //loop untuk membuat pola akhir
    for(int i = 0 ; i < n/2 - var; i++){
        for (int j = 0 ; j < (n/2) ; j++){
            cout<<" ";
        }
        for ( int x = 0 ; x < i + 2 ; x++){
            cout<<num;
            num = (num + 1) % 10;
            }
        cout<<endl;
    }
    
    return 0;
}