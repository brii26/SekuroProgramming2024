#include <iostream>
using namespace std;

int main(){
    int a = 10 ;
    int b = 20 ;
    int* pa = &a;
    int* pb = &b;
    int** ppa = &pa;
    int** ppb = &pb;
    //Asumsi address dari a = 0x111111
    //Asumsi address dari b = 0x222222
    //Asumsi address dari pa = 0x333333
    //Asumsi address dari pb = 0x444444

    cout<< a <<endl; // output = 10 ; karena program mengoutput value pada variabel a
    cout<< &a <<endl; // output = 0x111111; karena &a adalah memory address dari a
    cout<< pb <<endl; // output = 0x222222; karena pb menyimpan &b yang merupakan memory address dari b
    cout<< ppa <<endl; // output = 0x333333; karena ppa menyimpan &pa yang merupakan memory address dari pa

    cout<< *pa <<endl; // output = 10 ; karena *pa adalah value dari &a 
    cout<< *ppb <<endl; // output = 0x222222 ; karena *ppb adalah value dari &pb
    cout<< **ppa <<endl; // ouput = 10 ; karena **ppa adalah value dari value &pa (ppa = &pa; *ppa = value &pa ; **ppa = value &a)

    cout<< *pb * **ppb <<endl;// output = 400; karena *pb = value dari &b = 20 dan **ppb = value dari value &pb = 20, sehingga 20 * 20 = 400

    return 0;
}
