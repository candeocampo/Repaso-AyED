#include<iostream>
#include<stdio.h>
using namespace std;

//Escribir una función que retorne una lista apartir de la intersección de una pila y una cola.

struct Nodo{
    int Info;
    Nodo *sgte;
};

Nodo *interseccion(Nodo *Pila, Nodo *cfte, Nodo *cfin){
    Nodo *Lista=NULL;
    Nodo *ListaAuxPila=NULL;
    Nodo *ListaAuxCola=NULL;
    int valor;
    while(Pila!=NULL){
        valor=pop(Pila);
        push(ListaAuxPila,valor);
    }
    while(cfte!=NULL){
        valor=suprimir(cfte,cfin);
        agregar(cfte,cfin,valor);
    }
    while(ListaAuxPila!=NULL){
        int elemento;
        int encontro;
        elemento=pop(ListaAuxPila);
        encontro=buscar(ListaAuxCola,elemento);
        if(encontro>-1){
            insertarPrimero(Lista,elemento);
        }
        ListaAuxPila=ListaAuxPila->sgte;
    }
    return Lista;
}



int main(){



    return 0;
}
