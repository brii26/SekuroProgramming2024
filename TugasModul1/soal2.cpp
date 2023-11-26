#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    //input jumlah bilangan dan deklarasi variable
    int jumlah_bilangan ;
    float bilangan ; 
    float total = 0;
    cout<< "jumlah bilangan : ";
    cin>>jumlah_bilangan;

    //loop untuk menginput setiap bilangan 
    for (int i = 0 ; i < jumlah_bilangan ; i++){
        cout<<"bilangan "<<i+1<< " : ";
        cin>>bilangan;
        total += bilangan;
    }
    
    //output bilangan rata-rata
    cout<< " RATA-RATA : "<<setprecision(3)<< total / jumlah_bilangan; 
    return 0;
}
