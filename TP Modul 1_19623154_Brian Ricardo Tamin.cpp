#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main(){

    //deklarasi variabel pesawat -> character
    char pesawat;

    //menerima input user berupa char yg di masukan ke variabel pesawat
    cout<<"jenis pesawat : ";
    cin>>pesawat;

    //loop jika input tidak valid
    while(pesawat != 'a' && pesawat != 'b' && pesawat != 'o'){
        system("clear");
        cout<<"INPUT TIDAK VALID"<<endl<<"jenis pesawat : ";
        cin>>pesawat;
    }
    system("clear");
    
    //output
    switch(pesawat){
        case 'a':
            for (int i = 3; i > 0; i--){
                cout<<to_string(i) + " "<<flush;
                Sleep(1000);
            }
            cout<<"\nPESAWAT A BERANGKAT"; break;
        case 'b':
            for (int i = 5; i > 0 ; i--){
                cout<<to_string(i) + " "<<flush;
                Sleep(1000);
            }
            cout<<"\nPESAWAT B BERANGKAT"; break;
        case 'o':
            cout<<"PENERBANGAN DITUTUP";break;
        default:
            break;
    }

    return 0;
}
