#include<iostream>
using namespace std;
int main(){
    //format program
    cout<<"Program C++ Angka Prima";
    cout<<"\n========================\n";
    cout<<"Input salah satu bilangan bulat : ";

    //inisiasi dan input variabel
    int angka;
    int factor;
    cin>>angka;
    factor = 0 ;

    //loop untuk mengetahui bilangan prima 
    for (int i = 1 ; i <= angka ; i++){
        if (angka % i == 0){
            factor += 1;
        }
    }

    //output
    cout<<((factor == 2) ? to_string(angka) +  " angka prima" : to_string(angka) + " bukan angka prima");

    return 0;

}
