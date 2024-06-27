#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

bool vank(string jelszo){
    for (int i = 0; i < jelszo.length(); i++)
    {
        if(islower(jelszo[i]))
            return true;
    }
    return false;
}
bool vankn(string jelszo){
    for (int i = 0; i < jelszo.length(); i++)
    {
        if(isupper(jelszo[i]))
            return true;
    }
    return false;
}
bool vansz(string jelszo){
    for (int i = 0; i < jelszo.length(); i++)
    {
        if(isdigit((int)jelszo[i]))
            return true;
    }
    return false;
}
bool vans(string jelszo){
    string specialis = "*_'@";
    for (int i = 0; i < jelszo.length(); i++)
    {
        if(specialis.find(jelszo[i]) != string::npos)
            return true;
    }
    return false;
}

string general(){
    srand(static_cast<unsigned int>(time(0)));
    int random=0;
    int random2=0;
    string jelszo="";
    string karakter = "abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string szam = "0123456789";
    string specialis = "*_'@";
    for (int i = 0; i < 12; i++)
    {
        random = rand() % 3 + 1;
        if(random == 1){
            random2 = rand() % (karakter.length());
            jelszo += karakter[random2]; 
        }
        if(random == 2){
            random2 = rand() % (szam.length());
            jelszo += szam[random2];
        }
        if(random == 3){
            random2 = rand() % (specialis.length());
            jelszo += specialis[random2];
        }
        if(vank(jelszo) && vansz(jelszo) && vans(jelszo) && vankn(jelszo) && jelszo.length()>8)
            break;
    }
    return jelszo;
    
}

int main(){
    cout << general() << endl;
    return 0;
}