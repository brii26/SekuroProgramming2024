#include <iostream>
#include <math.h>
using namespace std;

float pi = 3.14;
//function luas lingkaran
float luas(float r){
    return pi * pow(r , 2);
}

int main(){
    //input jari -jari dan output luas lingkaran
    float radius;
    cout<<"jari - jari lingkaran = ";
    cin >>radius;
    cout<<"luas lingkaran = "<<luas(radius);

    return 0;
}
