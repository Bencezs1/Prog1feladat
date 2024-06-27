#include <iostream>

using namespace std;

struct Kal{
    int kor;
    double magassag;
    double suly;
    short int nem;

};

double Kaloria(Kal e){
    if (e.nem == 1){
        return (10*e.suly) + (6.25*e.magassag) - (5*e.kor) + 5;
    }
    else{
        return (10*e.suly) + (6.25*e.magassag) - (5*e.kor) - 161;
    }
}
int main(){
    Kal e1;
    cout << "Eletkorod: ";
    cin >> e1.kor;
    cout << "Magassagod (cm-ben): ";
    cin >> e1.magassag;
    cout << "Testsulyod (kg-ban): ";
    cin >> e1.suly;
    cout << "Nemed (0 = No), (1 = Ferfi): ";
    cin >> e1.nem;
    cout << "Napi kaloriabevitel szuksegleted: " << Kaloria(e1) << endl;
    return 0;
}