#include<iostream>
#include<stdio.h>
using namespace std;

//ENUNCIADO
/* Se tiene un archivo de disponibilidad para las habitaciones de un hotel 
en la costa de Verano2021.dat (sin Orden):
-Numero de Habitacion: 99999
-Tipo: 'S', 'D', 'T' o 'C' (Single, Doble, Triple o Cuádruple)
-Dias Disponibles de la Temporada: 999
-Precio por día de la habitación: 999 (entero)
Se pide:
a) Ordenar el archivo Verano2021.DAT por el numero de la habitación.
b) Armar una lista, ordenada por número de habitación y mostrarla por pantalla si 
el número de días disponibles es menor a 50 y son habitaciones singles o dobles. */ 


struct tInfo{ //tInfo info;
    int numHab;
    char tipo;
    int diasDisp;
    int precio;
};

struct Nodo{
    tInfo info;
    Nodo *sgte;
};


void insertarOrdenado(Nodo *&Lista, tInfo rinfo);
void liberar(Nodo*&Lista);
void mostrar(Nodo*Lista);

int main(){

    Nodo *listaA=NULL;
    Nodo *listaB=NULL;

    FILE *archiv;
    archiv=fopen("Verano2021.dat","rb");

    tInfo raux;
    fread(&raux,sizeof(struct info),1,archiv);
    while(!feof(archiv)){
        insertarOrdenado(listaA,raux);
        if((raux.diasDisp<50) && (raux.tipo=='S' || raux.tipo=='D')){
            insertarOrdenado(listaB,raux);
        }
        fread(&raux,sizeof(struct info),1,archiv);
    }
    fclose(archiv);

    archiv=fopen("Verano2021.dat","wb");
    Nodo *aux=listaA;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(struct tInfo),1,archiv); //cuando termine de escribir lo que tenia en la lista en el archivo.
        aux=aux->sgte;
    }
    fclose(archiv);
    liberar(listaA);

    //PUNTO B
    mostrar(listaB);
    liberar(listaB);




    return 0;
}

void insertarOrdenado(Nodo *&Lista, tInfo rinfo){
    Nodo *nuevo=new Nodo();
    nuevo->info.numHab=rinfo.numHab;
    nuevo->info.tipo=rinfo.tipo;
    nuevo->info.diasDisp=rinfo.diasDisp;
    nuevo->info.precio=rinfo.precio;
    nuevo->sgte=NULL;
    Nodo *aux=Lista; 
    Nodo *ant=NULL; 
    while(aux!=NULL && aux->info.numHab<rinfo.numHab){
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

void liberar(Nodo*&Lista){ 
    Nodo *aux; 
    while(Lista!=NULL){
        aux=Lista;
        Lista=Lista->sgte; 
        delete(aux);
    }
}

void mostrar(Nodo*Lista){
    Nodo *aux=Lista;
    while(aux!=NULL){
        cout<<aux->info.codP<<endl;
        cout<<aux->info.tipo<<endl; 
        cout<<aux->info.numHab<<endl;
        cout<<aux->info.precio<<endl;
        aux=aux->sgte; 
    }
}