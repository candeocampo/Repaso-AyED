#include<iostream>
#include<stdio.h>
using namespace std;

//ENUNCIADO DE EJERCICIO.
// Dado un archivo de registro(CodProd, tipodeProd) generar
// dos archivos ordenados (según el tip "A" o "B")
// por código de producto.

struct tInfo{
    int codP;
    char tipo;
};

struct Nodo{
    tInfo info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, tInfo rinfo);
void liberar(Nodo*&Lista);
void mostrar(Nodo*Lista);


int main(){

    //Creamos las dos listas para los archivos que tenemos que generar.
    Nodo *listaA=NULL;
    Nodo *listaB=NULL;
    

    //Imaginemos que ya tenemos el archivo.
    FILE *arch;
    FILE *archA;
    FILE *archB;

    arch=fopen("arch.data","rb");
    tInfo raux;

    fread(&raux,sizeof(struct tInfo),1,arch);
    while(!feof(archiv)){
        if(raux.tipo=='A'){
            insertarOrdenado(listaA,raux);
            fread(&raux,sizeof(struct tInfo),1,arch);
        }
        else{
            insertarOrdenado(listaB,raux);
            fread(&raux,sizeof(struct tInfo),1,arch);
        }
    }
    fclose(arch);

    archA=fopen("archA.dat","wb");
    Nodo *aux=listaA; //recorremos la lista.
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(struct tInfo),1,archA);
        aux=aux->sgte;
    }
    fclose(archA);
    mostrar(listaA);
    liberar(listaA); //obligatorio.

    archB=fopen("archB.dat","wb");
    aux=listaB;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(struct tInfo),1,archB);
        aux=aux->sgte;
    }
    fclose(archB);
    liberar(listaB);

    return 0;
}


void insertarOrdenado(Nodo *&Lista, tInfo rinfo){
    Nodo *nuevo=new Nodo();
    nuevo->info.codP=rinfo.codP;
    nuevo->info.tipo=rinfo.tipo;
    nuevo->sgte=NULL;
    Nodo *aux=Lista; 
    Nodo *ant=NULL; 
    while(aux!=NULL && aux->info.codP<rinfo.codP){
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
        aux=aux->sgte; 
    }
}


