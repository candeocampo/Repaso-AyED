#include<iostream>
#include<stdio.h>
using namespace std;


struct Nodo{
    int info;
    Nodo *sgte;

};

void agregarPrimero(Nodo *&Lista,int valor);
int sacarPrimero(Nodo *&Lista);

void mostrar(Nodo*Lista);
void liberar(Nodo*&Lista);

void insertarOrdenado(Nodo *&Lista, int valor);
Nodo *buscar(Nodo *Lista,int valor);
void buscarYMostrar (Nodo *Lista, int valor);

int main(){

    Nodo *lista=NULL;

    //agregarPrimero(lista,1);
    //agregarPrimero(lista,2);
    //agregarPrimero(lista,3);

    insertarOrdenado(lista,8);
    insertarOrdenado(lista,2);
    insertarOrdenado(lista,1);

    //Para usar la busqueda utilizamos un puntero de resultado pues nos duvuelve un puntero.
    //Nodo *rdo;
    //rdo=buscar(lista,3);
    //if(rdo!=NULL){
    //    cout<<rdo->info<<endl;
    //}
    //else{
        //cout<<"No se encontro."<<endl;
    //}

    buscarYMostrar(lista,8);


    mostrar(lista);
    liberar(lista);

    //int rdo;
    //rdo=sacarPrimero(lista);
    //cout<<rdo<<endl;
    //rdo=sacarPrimero(lista);
    //cout<<rdo<<endl;



    return 0;
}

void agregarPrimero(Nodo *&Lista,int valor){
    Nodo *nuevo=new Nodo();
    //Cargar el nodo
    nuevo->info=valor;
    nuevo->sgte=Lista;
    //Enlazar
    Lista=nuevo;
}

int sacarPrimero(Nodo *&Lista){
    int ret;
    ret=Lista->info;
    Nodo *aux=Lista;
    Lista=Lista->sgte;
    delete(aux);
    return ret;

}

//para mostrar la lista, sin sacar elementos.
void mostrar(Nodo*Lista){
    Nodo *aux=Lista;
    while(aux!=NULL){
        cout<<aux->info<<endl; //muestra
        aux=aux->sgte; //avanza al que le sigue.
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

void insertarOrdenado(Nodo *&Lista, int valor){

    //crear Nodo
    Nodo *nuevo=new Nodo();
    //cargar nodo.
    nuevo->info=valor;
    nuevo->sgte=NULL;  //Va NULL pq no sabemos donde va a ir.
    //Enlazarlo ¿En dónde?
    Nodo *aux=Lista; //poder recorrer sin modificar la lista.
    Nodo *ant=NULL; //este es el q'me va a permitir enlazar.
      //BUSCAR!!    
    while(aux!=NULL && aux->info<valor){
        ant=aux;
        aux=aux->sgte;

    }
    if(ant==NULL){ //1) lista vacia o 2) debo insertar al principio.
        Lista=nuevo;
    }
    else{ //1) en alguna parte de la lsita o 2) agregar al final.
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux;

}

Nodo *buscar(Nodo *Lista,int valor){
    Nodo *aux=Lista;
    while(aux!=NULL && aux->info!=valor){
        aux=aux->sgte;
    }
    return aux;

}

void buscarYMostrar (Nodo *Lista, int valor){
    Nodo *aux=Lista;
    while(aux!=NULL && aux->info!=valor){
        aux=aux->sgte;
    }
    if(aux==NULL){
        cout<<"No se encontro el valor."<<endl;
    }
    else{
        cout<<"Encontro: "<<aux->info<<endl;
    }
}







