#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <unistd.h>
using namespace std;

// lokasi
void lokasi(float x, float y){
    system("clear");
    cout<<fixed<<setprecision(2)<<"==================================================="<<"\nLokasi Drone ("<<x<<" , "<<y<<")"<<"\n===================================================\n";
}

// interface
 int interface(float x , float y, int n){
    lokasi(x,y);
    cout<<"1. Simulasi Gerak Drone dengan Perpindahan\n2. Simulasi Gerak Drone dengan Kecepatan dan Waktu\n3. Undo\n4. Redo\n5. exit\n\nMasukkan angka (1-5) : ";
    cin>>n;
    return n;
}

// gerak perpindahan
void gerak(float* Px, float* Py, float a, float b){
    system("clear");
    cout<<"Gerak drone pada sumbu-x : "; cin>>a;
    cout<<"Gerak drone pada sumbu-y : "; cin>>b;
    *Px += a; 
    *Py += b;

}

// gerak kecepatan dan waktu
void gerak_2(float* Px, float* Py, float v, float t, float tetha){
    system("clear");
    cout<<"Kecepatan drone bergerak : "; cin>>v;
    cout<<"Waktu tempuh drone : "; cin>>t;
    cout<<"Sudut : "; cin>>tetha;
    *Py += (v * t * sin(tetha/180 * 3.14));
    *Px += (v * t * cos(tetha/180 * 3.14));
}

//undo
void undo(float* Px, float* Py, int index, vector<vector<float>>datas, int* pointer){
    system("clear");
    if (index > 0){ 
        index--;
        *Px = datas[index][0];
        *Py = datas[index][1];
        cout<<"Undo berhasil !"<<flush;usleep(600000);
        *pointer = index;
    }
    else{
        system("clear");
        cout<<"Tidak dapat Undo!"<<flush;
        usleep(600000);
    }
}

//redo
void redo(float* Px, float* Py, int index, vector<vector<float>>datas, int* pointer){
    system("clear");
    if (index < datas.size()-1){
        index++;
        *Px = datas[index][0];
        *Py = datas[index][1];
        cout<<"Redo berhasil !"<<flush;usleep(600000);
        *pointer = index;
    }
    else{
        system("clear");
        cout<<"Tidak dapat Redo!"<<flush;
        usleep(600000);
    }
}

// main function
int main(){

    //inisiasi dan deklarasi
    vector<vector<float>> datas;
    float x = 0; float x_gerak ; float* Px = &x;
    float y = 0; float y_gerak ; float* Py = &y;
     int value; int temp_index; float v; float t; 
     float tetha; bool history = false; int n = 0 ;
    int* P_temp_index = &temp_index; bool angka_valid = true;

    // interface loop
    do
    {
        if (history == false && angka_valid){
            datas.push_back({x , y});
            temp_index = datas.size()-1;
        }
        value = interface(x,y,n);
        switch(value)
        {
            case 1 :  angka_valid = true; history = false; gerak(Px, Py, x_gerak, y_gerak);break;
            case 2 :  angka_valid = true; history = false; gerak_2(Px, Py, v , t, tetha);break;
            case 3 :  angka_valid = true; history = true; undo(Px, Py, temp_index, datas, P_temp_index);break;
            case 4 :  angka_valid = true; history = true; redo(Px, Py, temp_index, datas, P_temp_index);break;
            case 5 : system("clear");cout<<"Simulasi Berakhir";break;
            default : angka_valid = false; system("clear"); cout<<"Masukkan angka valid"<<flush<<usleep(600000);break;
        }
    }
    while( value != 5);

    return 0;
}
