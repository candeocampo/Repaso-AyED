/* Se tiene un vector de Reservas de los hoteles de Pinamar para el verano 2024, que contiene el detalle
de las reservas de cada hotel con los siguientes campos:
-Codigo de Hotel
-Cantidad de Reservas
-Cantidad de dias disponibles en la temporada.
Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas por un sitio web de viajes,
cada nodo de la lista contiene:
-Codigo de Hotel
-Cantidad de dias Reservados
Se pide, actulizar el vector Reservas con la información que hay en la lista, incrementando la cantidad de reservas
por cada una que aparezca en la lista, como así actualizando la cantidad de días disponibles en base a los días
reservados. 
Ejemplo: Si en la lita el hotel 23 tiene 2 dias reservados, esos 2 dias se deben restar en el campo de 
cantidad de dias disponibles del vector.
Se sabe que cómo máximo hay 50 hoteles. */


#include<iostream>
#include<stdio.h>
using namespace std;

struct Hotel{
    int codH;
    int cantR;
    int cantDias;
};

struct Reserva{
    int codH;
    int diasReser;
};

struct Nodo{
    Reserva Info;  
    Nodo *sgte;
};


int main(){

    Hotel Vec[50];
    int len;

    Nodo *Lista;
    Nodo *aux=Lista;

    while(aux!=NULL){
        int pos=buscar(vec[],len,aux->Info.codH);
        if(pos>-1){
            vec[pos].cantDias +=aux->Info.diasReser;
            if(vec[pos].cantDias>aux->Info.diasReser){
                vec[pos].cantDias -=aux->Info.diasReser;
            }
        }
        else{
            cout<<"Lo siento, los días reservados superan a los disponibles."<<endl;
        }
        aux=aux->sgte;
    }
    liberar(Lista);

    return 0;
}