#include<iostream>
#include<stdio.h>
using namespace std;

//ENUNCIADO DE EJERCICIO
//Dada 2 colas, generar una nueva con la unión de ambas.
//UNIÓN= los elementos de las dos colas en la nueva cola.

struct Nodo{
    int info;
    Nodo *sgte;
};

void agregar(Nodo *&fte, Nodo *&fin,int valor);
int suprimir(Nodo *&fte, Nodo *&fin);



void unionColas(Nodo *cFteA, Nodo*cFinA, Nodo *cFteB, Nodo *cFinB, Nodo *&cFteC, Nodo *&cFinC){

    int valor;
    while(cFteA!=NULL){
        valor=suprimir(cFteA,cFinA);
        agregar(cFteC,cFinC,valor);
    }
    while(cFteB!=NULL){
        valor=suprimir(cFteB,cFinB);
        agregar(cFteC,cFinC,valor);
    }

}

int main(){




    return 0;
}

void agregar(Nodo *&fte, Nodo *&fin,int valor){
    Nodo *nuevo=new Nodo(); //creamos el nodo.
    nuevo->info=valor; //le cargamos el valor.
    nuevo->sgte=NULL; 
    //Encolarlo.
    if(fte==NULL){ //si no hay nada en la cola.
        fte=nuevo;
    }
    else{
        fin->sgte=nuevo;
    }
    fin=nuevo;
}

int suprimir(Nodo *&fte, Nodo *&fin){
    int ret;
    ret=fte->info; //Ó aux->info.
    Nodo *aux=fte;
    fte=aux->sgte; //ó fte->sgte;
    if(fte==NULL){ //validamos que no haya quedado ningún elemento en la cola.
        fin=NULL;
    }
    delete (aux);
    return ret;
}