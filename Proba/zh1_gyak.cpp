#include <iostream>
#include <algorithm>

using namespace std;

int hanydb(int n){
    int ossz = 0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            ossz++;
        }
    }
    return ossz;
}

void szoszt(int a, int b){
    for(int i=1;i<=100;i++){
        if(i%a==0 || i%b==0){
            cout << i << endl;
        }
    }
}

void rendez(int t[10],int sz){
    sort(t+sz,t+10);
}

void csrendez(int t[10]){
    sort(t,t+10);
    reverse(t,t+10);
}

double atlag(int t[5]){
    double ossz=0.0;
    for(int i=0;i<5;i++){
        ossz+=t[i];
    }
    return ossz/5;
}

struct Monitor{
    int szelesseg;
    int magassag;
    string marka;
};


int main(){
    cout << hanydb(20) << endl;;
    szoszt(5,48);
    int t[10] = {4,5,7,3,5,6,9,1,4,5};
    rendez(t,4);
    for(int i=0;i<10;i++){
        cout << t[i] << " ";
    }
    cout << endl;
    csrendez(t);
    for(int i=0;i<10;i++){
        cout << t[i] << " ";
    }
    cout << endl;
    int sz[5];
    for(int i=0;i<5;i++){
        cout << i+1 << ". szam: ";
        cin >> sz[i];
    }
    cout << "Atlag felettiek: " << endl;
    for(int i=0;i<5;i++){
        if(sz[i] > atlag(sz)){
            cout << sz[i]  << " ";
        }
    }
    cout << endl;

    Monitor to[5];
    for(int i=0;i<5;i++){
        Monitor m;
        cout << "Szelesseg: ";
        cin >> m.szelesseg;
        
        cout << "Magassag: ";
        cin >> m.magassag;
        
        cout << "Marka: ";
        cin >> m.marka;
        to[i] = m;
    }
    Monitor s[5];
    int j=0;
    for(int i = 0;i<5;i++){
        if(to[i].marka == "Samsung"){
            s[j] = to[i];
            j++;
        }
    }
    for(Monitor i : s){
        cout << i.szelesseg << " " << i.magassag << " " << i.magassag << endl;
    }
    return 0;
}