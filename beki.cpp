#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Allat{
    string nev;
    int kor;
};

istream& operator>>(istream& i, Allat& a){
    i >> a.nev;
    i >> a.kor; 
    return i;
}
void operator<<(ostream& o, vector<Allat>& v){
    for(int i=0;i<v.size();i++){
        cout << v[i].nev << " " << v[i].kor << endl;
    }
}

int main(){
    /*vector<Allat> v;
    int szam;
    cout << "szam: " << endl;
    cin >> szam;
    for(int i=0;i<szam;i++){
        Allat a;
        cin >> a;
        v.push_back(a);
    }
    cout << v;*/

    vector<Allat> v2;
    ifstream be("allat.txt");
    Allat a;
    while(be >> a){
        v2.push_back(a);
    }
    cout << v2;
    return 0;
}