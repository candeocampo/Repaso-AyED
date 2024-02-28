#include<iostream>
#include<stdio.h>
using namespace std;

// Dado un vector acerca del stock de un déposito que contiene el CodP y la cantidad de
// unidades diponibles para la venta (Se sabe que max 150 prods), determinar:
// 1) ¿Cuál es el producto que más unidades tiene?
// 2) ¿Cuál es el producto que menos unidades tiene?
// 3) Indicar la cantidad total de productos almacenados según el vector.

struct Prod{
    int codP;
    int cant;
};

void masUnidades(Prod vec[],int valor){

    int pos=0;
    int max=vec[0]; //estoy guardando que el máximo de entradas esta en la posición 0.

    for(int i=1;i<len;i++){
        if(vec[i].cant>max){
            pos=i; //paso la posición del que tiene mayor unidades.
            max=vec[i].cant;
        }
    }

    cout<<"El producto "<<vec[pos].codP<<" tiene un máx de unidades: "<<max<<endl;
}

void minUnidades(Prod vec[],int valor){

    int pos=0;
    int min=vec[0].cant;

    for(int i=1;i<len;i++){
        if(vec[i].cant<min){
            pos=i;
            max=vec[i].cant;
        }
    }
    cout<<"El producto "<<vec[pos].codP<<" tiene un min de unidades: "<<min<<endl;

}

void sumatoria(Prod vec[],int valor){

    int suma=0;
    for(int i=0;i<len;i++){
        suma=suma+vec[i].cant;
    }
    cout<<"La suma de los productos es: "<<suma<<endl;

}

int main(){

    Prod vec[150];
    int len; //no va en 0 esta vez.

    masUnidades(vec,len);
    minUnidades(vec,len);
    sumatoria(vec,len);

    return 0;
}