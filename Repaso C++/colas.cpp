#include<iostream>
#include<stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void agregar(Nodo *&fte, Nodo *&fin,int valor);
int suprimir(Nodo *&fte, Nodo *&fin);


int main(){
    //Definición de la cola.
    Nodo *fte=NULL;
    Nodo *fin=NULL;

    agregar(fte,fin,1);
    agregar(fte,fin,2);
    agregar(fte,fin,3);
    agregar(fte,fin,4);

    //si cargamos por usuario.
    int carga;
    cout<<"Ingrese un valor (0 para finalizar): ";
    cin>>carga;
    while(carga!=0){
        agregar(fte,fin,carga);
        cout<<"Ingrese un valor (0 para finalizar): ";
        cin>>carga;
    }


    int rdo;
    while(fte!=NULL){
        rdo=suprimir(fte,fin);
        cout<<rdo<<endl;
    }

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