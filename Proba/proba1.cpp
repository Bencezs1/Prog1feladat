#include <iostream>
#include <cmath>
#include <string>

double *Masodfoku(double a, double b, double c){
    double *eredmeny = (double *)malloc(2 * sizeof(double));
    double diszkriminans = (b*b) - (4*a*c);
    double eredmeny1,eredmeny2;
    if(diszkriminans > 0){
        eredmeny1 = (-b + sqrt(diszkriminans)) / 2*a;
        eredmeny2 = (-b - sqrt(diszkriminans)) / 2*a;
        eredmeny[0] = eredmeny1;
        eredmeny[1] = eredmeny2;
    }
    else{
        eredmeny1 = -b / (2 * a);
        eredmeny[0] = eredmeny[1] = eredmeny1;
    }
    return eredmeny;
}

int main(){
    /*double a,b,c;
    std::cin >> a >> b >> c;
    double *megoldas = Masodfoku(a,b,c);
    std::cout << megoldas[0] << "\n" << megoldas[1] << std::endl;
    free(megoldas);*/
    int a = 5;
    int *b = &a;
    std::cout << b << " " << &b << " " << &a << std::endl;
    return 0;
}