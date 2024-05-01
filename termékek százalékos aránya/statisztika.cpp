#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void beolvas(ifstream& be,vector<string>& v,int& vszam){
    string n[10] = {"0","1","2","3","4","5","6","7","8","9"};
    string sor;
    int vane = 0;
    while(be >> sor){
        for(int i=0;i<10;i++){
            if(n[i] == sor){
                vane = 1;
                vszam++;
                break;
            }
        }
        if(vane == 0){
            v.push_back(sor);
        }
        vane = 0;
    }
}

int main(){
    map<string,double> termek;
    ifstream be("termekek.txt");
    vector<string> v;
    int vszam = 0;
    beolvas(be,v,vszam);
    for(string i : v){
        if(termek.find(i) == termek.end()){
        termek[i] = 1.0;
        }
        else{
            termek[i] += 1.0;
        }
    }
    for(auto i = termek.begin();i!=termek.end();i++){
        i->second = (i->second/vszam);
    }
    for(auto i = termek.begin();i!=termek.end();i++){
        cout << i->first << " " << round(i->second*100) << "%" << endl;
    }
    return 0;
}