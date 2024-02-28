// Se tiene un archivo de peliculas infantiles en una plataforma digital con los titulos
// disponibles para la Argentina. El archivo se llama "infatil.dat"
// Cod Pelicula: 999999
// Cant de Opiniones Positivas: 999999
// Cantidad de Vistas: 999999

//Se pide:
//a) Ordenar el archivo por opiniones positivas.
//b) Listar las 10 peliculas más vistas tuvieron tal listar incluir toda la información
// referente a la  
// Nota: sólo debe leer 1 vez en el archivo. Se sabe que no hay más de 50 pelis.

#include<iostream>
#include<stdio.h>
using namespace std;

struct Peli{
    int codP;
    int opPos;
    int cantV;
};

struct Nodo{
    Peli Info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, Peli Info){
    Nodo *nuevo=new Nodo();
    nuevo->Info=Info.codP;
    nuevo->Info=Info.cantV;
    nuevo->Info=Info.opPos;
    nuevo->sgte=NULL;
    Nodo *ant=NULL;
    Nodo *aux=Lista;
    while(aux!=NULL && aux->Info.opPos<Info.opPos){
        ant=aux;
        aux=aux->sgte;
    }
    if(ant==NULL){
        Lista=nuevo;
    }
    else{
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux;
}

int main(){


    FILE *arch=fopen("Infantil.dat","rb");
    Peli Vec[50];
    int len=0;
    int len2=0;

    Nodo *Lista=NULL;

    Peli aux;
    fread(&aux,sizeof(struct Peli),1,arch);
    while(!feof(arch)){
        insertarOrdenado(Lista,aux);


        fread(&aux,sizeof(struct Peli),1,arch);
    }




    return 0;
}
