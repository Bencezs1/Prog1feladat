#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void operator<<(vector<int>& a,int szam){
    a.push_back(szam);
}

void feltolt(int *a, int size){
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
    }
}

void print(int* a, int meret){
    for (int i = 0; i < meret; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}



int main(){
    vector<int> l;
    for(int i=0;i<5;i++){
        l.push_back(i);
    }

    reverse(l.begin(),l.end());
    for(int i : l){
        cout << i << endl;
    }
    cout << *max_element(l.begin(),l.end()) << endl;

    cout << count(l.begin(),l.end(),2) << endl;

    cout << l.size() << endl;

    for(int i : {1,2,3,4,5}){
        find(l.begin(),l.end(),4);
    }

    l << 8;
    for(int i : l){
        cout << i << " ";
    }
    cout << endl;
    int tomb[5];
    feltolt(tomb,5);
    print(tomb,5);
    
    
    return 0;
}