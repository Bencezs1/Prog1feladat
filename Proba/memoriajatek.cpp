#include <iostream>


void Kiir(int *tomb[5][2]){
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            std::cout << tomb[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Ellenoriz(int *tomb[5][2]){
    int hany=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            if(tomb[i][j] == 0){
                hany++;
            } 
        }
    }
    return hany == 10 ? true : false;
}

void Eltavolit(int sor,int oszlop,int sor2, int oszlop2,int *tomb[5][2]){
    tomb[sor-1][oszlop-1] = 0;
    tomb[sor2-1][oszlop2-1] = 0;
}




int main(){
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int *pa = &a,*pb = &b, *pc = &c, *pd = &d, *pe = &e;
    int *tomb[5][2];
     tomb[0][0] = pa;
    tomb[0][1] = pb;
    tomb[1][0] = pc;
    tomb[1][1] = pd;
    tomb[2][0] = pe;
    tomb[2][1] = pa; 
    tomb[3][0] = pb; 
    tomb[3][1] = pc;
    tomb[4][0] = pd;
    tomb[4][1] = pe;
    do{
        Kiir(tomb);
        int sor, oszlop, sor2, oszlop2;
        std::cout << "Kerek egy sorszamot: " << std::endl;
        std::cin >> sor;
        std::cout << "Kerek egy oszlop szamot" << std::endl;
        std::cin >> oszlop;
        std::cout << "Kerek meg egy sorszamot: " << std::endl;
        std::cin >> sor2;
        std::cout << "Kerek meg egy oszlop szamot" << std::endl;
        std::cin >> oszlop2;
        int *elso = tomb[sor-1][oszlop-1];
        int *masodik = tomb[sor2-1][oszlop2-1];
        if(*elso == *masodik){
            std::cout << *elso << " = " << *masodik << std::endl;
            std::cout << "Talalt\n" << std::endl;
            Eltavolit(sor,oszlop,sor2,oszlop2,tomb);
        }
        else{
            std::cout << *elso << " != " << *masodik << std::endl;
            std::cout << "Nem talalt\n" << std::endl;
        }
    }while(!Ellenoriz(tomb));
    std::cout << "Gratulalok! Nyertel!" << std::endl;
    return 0;
}