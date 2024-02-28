#include<iostream>
#include<stdio.h>
using namespace std;

//ENUNCIADO DE EJERCICIO
/* Dado un vector de registro de 20 posiciones que contiene: ID_prod, unidades en stock
Además se cuenta con una lista de los nuevos pedidos que ingresaron 
(Id_prod y unidades que entraron).
Se pide actualizar el vector con los nuevos ingresos. */

//osea deberiamos, 1)recorrer la lista y buscar los productos del vector
//2) y actualizar el campo de unidades.


struct tinfo{
    int idProd;
    int stock;
};

struct Nodo{
    tinfo Info;
    Nodo *sgte;
};


int buscar(tInfo vec[],int len, int valor);
void liberar(Nodo*&Lista);

int main (){

    tinfo vec[20];
    int len;
    
    Nodo *lista; //No la inicio en NULL pq se supone que ya viene dada.
    Nodo *aux=lista; //cuando queremos recorrer la lista, debemos hacer un puntero auxiliar.
    while(aux!=NULL){

        pos=buscar(vec,len,aux->Info.idProd);
        if(pos>-1){
            vec[pos].stock=vec[pos].stock+aux->Info.stock; //en la lista incrementamos el vector.
        }
        else{
            cout<<"No se encontro el producto."<<endl;
        }
        
    }
    liberar(lista);

    return 0;
}

int buscar(tInfo vec[],int len, int valor){
    int i=0;
    while(i<len && vec[i].idProd!=valor){
        i++;
    }
    if(i==len){
        return -1;
    }
    else{
        return i;
    }
}

void liberar(Nodo*&Lista){ //A cada nodo le hacemos delete.
    Nodo *aux; //Lo declaro, NO le asigno a lista pq estmaos eliminando varios nodos.
    while(Lista!=NULL){
        aux=Lista;
        Lista=Lista->sgte; //ó Lista=aux->sgte;
        delete(aux);
    }
}