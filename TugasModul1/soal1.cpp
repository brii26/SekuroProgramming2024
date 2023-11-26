#include <iostream>
using namespace std;
int main(){
    //input dan deklarasi data
    int angka_awal;
    int angka_akhir;
    cin>>angka_awal;
    cin>>angka_akhir;

    //loop untuk mengoutput bilangan genap diantara angka_awal dan angka_akhir
    while (angka_awal <= angka_akhir){
        if ( angka_awal % 2 == 0){
            cout<<angka_awal<<" ";
        }
        angka_awal++;
    }
    return 0;
}
