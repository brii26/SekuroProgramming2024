#include <iostream>
using namespace std;
int main(){
    //deklarast dan input data
    int n ;
    cout<<"n : ";
    cin>>n;

    //loop untuk mengoutput baris 1 sampe n 
    for (int i = 0 ; i <= n ; i++){
        for (int j = 0 ; j < i ; j++){
            cout<<'*';
        }
        cout<<endl;
    }
    //loop untuk mengoutput baris n+1 sampe 2*n
    for (int i = n-1; i > 0; i--){
        for (int j = i ; j > 0; j--){
            cout<<'*';
        }
        cout<<endl;
    }

    return 0;
}
