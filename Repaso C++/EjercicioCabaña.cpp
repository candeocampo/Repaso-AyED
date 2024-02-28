/* Se tiene un vector de Reservas de cabaña de la Patagoia, en las que se aplicó un beneficio 
para turistas argentinos con los sig campos:
-Codigo de la cabaña
-Cantidad de Reservas de Turitas Argentinos
-Cantidad de Huéspedes
-Monto Abonado
Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas, cada nodo de la lista contiene:
-Codigo de la cabaña
-Aplica beneficio ('S' o 'N')
-Cantidad de Huespedes
-Monto Abonado
Se pide, actualizar el vector Reservas con la información que hay en la lista. Por cada reserva en la que SI haya aplicado el beneficio,
debe actulizar la cantidad de huéspedse en el vector, incrementar 1 en la cantidad de reservas y acumular el monto abonado.
Se sabe que cómo máximo hay 100 cabañas. */

#include<iostream>
#include<stdio.h>
using namespace std;

struct Cabaña{
    int codC;
    int turArg;
    int cantH;
    int montoAbonado;
};

struct Reserva{
    int codC;
    char aplica;
    int cantH;
    int montoAbonado;
};

struct Nodo{
    Reserva Info;
    Nodo *sgte;
};

int main(){

    Cabaña vec[100];
    int len;

    Nodo *Lista;
    Nodo *aux=Lista;
    while(aux!=NULL){
        int pos=buscar(vec,len,aux->Info.codC);
        if(pos>-1){
            if(aux->Info.aplica=='S'){
                vec[pos].cantH +=aux->Info.cantH; //actualizar la cantidad de huespedes.
                vec[pos].turArg +=1; //incrementar la cantidad de reservas en 1.
                vec[pos].montoAbonado+=aux->Info.cantH; //acumular el monto abonado.
            }
        }
        aux=aux->sgte;
    }
    liberar(Lista);

    return 0;
}


