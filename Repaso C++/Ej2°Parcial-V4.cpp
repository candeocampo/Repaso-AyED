#include<iostream>
#include<stdio.h>
using namespace std;

//ENUNCIADO DE EJERCICIO
//Dada 2 colas, generar una pila con la unión de ambas.


void push(Nodo *&pila,int valor); 
int pop(Nodo *&pila);

void agregar(Nodo *&fte, Nodo *&fin,int valor);
int suprimir(Nodo *&fte, Nodo *&fin);

void unionColasEnPila(Nodo *cFteA, Nodo*cFinA, Nodo *cFteB, Nodo *cFinB, Nodo *&pila){

    int valor;
    while(cFteA!=NULL){
        valor=suprimir(cFteA,cFinA);
        push(pila,valor);
    }
     while(cFteA!=NULL){
        valor=suprimir(cFteB,cFinB);
        push(pila,valor);
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

void push(Nodo *&pila,int valor){
    Nodo *nuevo=new Nodo();   //1) Creamos el nodo nuevo: pedimos memoria
    nuevo->info=valor;        //2) Cargamos el nodo.
    nuevo->sgte=pila;         
    pila=nuevo;               //3) Conectar.
}

int pop(Nodo *&pila){

    int ret; 
    ret=pila->info;
    Nodo *aux=pila;
    pila=aux->sgte;
    delete aux;
    return ret;
}