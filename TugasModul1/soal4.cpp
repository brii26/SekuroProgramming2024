#include<iostream>
using namespace std;
int main(){
    //inisiasi variabel
    float bukan_kabisat;
    int tahun ;

    //format input dan input variabel
    cout<<"Tentukan tahun kabisat\n";
    cout<<"Tahun : ";
    cin>>tahun;


    //output
    bukan_kabisat = (tahun % 400 != 0 && tahun % 100 == 0) || (tahun % 400 != 0 && tahun % 100 != 0 && tahun % 4 != 0);
    cout<<((bukan_kabisat) ? "bukan kabisat" : "kabisat");
    return 0;
}
