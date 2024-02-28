/*Se tiene un vector de Matriculas para una escuela de la ciudad, para el 2024, que contiene un resumen de matrículas abonadas, con los siguientes campos:
-Codigo del Curso
-Cantidad de Alumnos
-Monto Facturado
Además, se cuenta con una lista ordenada que contiene las últimas reservas de matrículas, cada nodo de la lista contiene:
-Codigo del Curso
-Monto Facturado
Se pide, actualizar el vector Matrículas con la información que hay en la lista. por cada reserva, debe actualizar la
cantidad del monto facturado, como así incrementar 1 la cantidad de alumnos. Se sabe que cómo Máximo hay 30 cursos. */

#include<iostream>
#include<stdio.h>
using namespace std;

struct Matriculas{
    int cod;
    int cantA;
    int factura;
};

struct Reserva{
    int cod;
    int factura;
};

struct Nodo{
    Reserva Info;
    Nodo *sgte;
};

int buscar(Matriculas Vec[], int len, int valor){
    int i;
    while((i<len) && (aux->Info.cod != valor)){
        len++;
    }
    if(i==len){
        return -1;
    }
    else{
        return i;
    }
}

void liberar(Nodo *&Lista){
    Nodo *aux;
    while(Lista!=NULL){
        aux=Lista;
        Lista=Lista->sgte;
        delete(aux);
    }
}

int main(){

    Matriculas vec[30];
    int len;
    Reserva Info;
    Nodo *Lista;
    Nodo *aux=Lista;
    while(aux!=NULL){
        int ret=buscar(vec,len,aux->Info.cod);
        if(ret>-1){
            vec[ret].factura=aux->Info.factura;
            vec[ret].cantA +=1;
        }
        aux=aux->sgte;
    }
    liberar(Lista);

    return 0;
}
