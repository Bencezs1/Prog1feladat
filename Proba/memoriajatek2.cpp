#include <iostream>

using namespace std;

void Kiir(int *tomb1[5],int **tomb2[5]){
    for(int i = 0;i<5;i++){
        cout << tomb1[i] << " " << tomb2[i] << endl;
    }
}

void Eltavolit(int sor, int oszlop, int sor2, int oszlop2, int *a[], int **b[]){
    if(oszlop == 1)
        a[sor-1] = NULL;
    else
        b[sor-1] = NULL;
    if(oszlop2 == 1)
        a[sor2-1] = NULL;
    else
        b[sor2-1] = NULL;
}

bool Ellenoriz(int *tomb1[], int **tomb2[]){
    int hany = 0;
    for(int i = 0; i < 5; i++){
        if(tomb1[i] == NULL && tomb2[i] == NULL)
            hany++;
    }
    return hany == 5 ? true : false;
}


int main(){
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int *pa = &a,*pb = &b, *pc = &c, *pd = &d, *pe = &e;
    int *cim1[5] = {pa,pb,pc,pd,pe};
    int **cim2[5] = {&pa,&pb,&pc,&pd,&pe};

    do{
        Kiir(cim1,cim2);
        int sor, oszlop, sor2, oszlop2;
        cout << "Kerek egy sorszamot: " << endl;
        cin >> sor;
        cout << "Kerek egy oszlop szamot" << endl;
        cin >> oszlop;
        cout << "Kerek meg egy sorszamot: " << endl;
        cin >> sor2;
        cout << "Kerek meg egy oszlop szamot" << endl;
        cin >> oszlop2;
        if(cim1[sor-1] == NULL || cim2[sor-1] == NULL)
        {
            cout << "Ezt szamot mar felhasznaltad" << endl;
            cout << endl;
            continue;
        }
        int *elso = oszlop == 1 ? cim1[sor-1] : *cim2[sor-1];
        int *masodik = oszlop2 == 1 ? cim1[sor2-1] : *cim2[sor2-1];
        if(*elso == *masodik){
            cout << *elso << " = " << *masodik << endl;
            cout << "Talalt\n" << endl;
            Eltavolit(sor,oszlop,sor2,oszlop2,cim1,cim2);
        }
        else{
            cout << *elso << " != " << *masodik << endl;
            cout << "Nem talalt\n" << endl;
        }
    }while(!Ellenoriz(cim1,cim2));
    return 0;
}