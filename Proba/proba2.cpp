#include <iostream>


using namespace std;

int most(short int tomb[10]){
    int szamlalo = 0;
    int sz2 = 0;
    for(int i=0;i<10;i++){
        if(tomb[i] == 0){
            szamlalo++;
        }
        else{
            if(sz2 < szamlalo){
                sz2 = szamlalo;
            }
            szamlalo = 0;
        }
    }
    return sz2;
    

}

int main(){
    short int arr[10] = {0,0,1,1,0,0,0,1,1,0};
    cout << most(arr) << endl;
    return 0;
}