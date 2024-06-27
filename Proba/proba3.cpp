#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct szemely{
    string nev;
    int kor;
};

ostream& operator<<(ostream& os,szemely& sz1){
    return os << sz1.nev << " " << sz1.kor << " ";
}

int test(int a, int b){
    return a+b;
}
int test(double a, double b){
    return a+b;
}

int main(){
    szemely sz;
    szemely sz2;
    sz.nev = "Kiss Csaba";
    sz.kor = 40;
    sz2.nev = "Nagy Imre";
    sz2.kor = 20;

    cout << sz << " " << sz2 << endl;

    cout << test(5,4) << " " << test(5.2,4.4) << endl;
    return 0;
}