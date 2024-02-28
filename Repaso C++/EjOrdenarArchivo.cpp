#include<iostream>
#include<stdio.h>
using namespace std;

//Dado un archivo de enteros, ordenarlo.

struct Nodo{
    int info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, int valor);
void liberar(Nodo*&Lista);
void mostrar(Nodo*Lista);

int main(){

    /* FILE *archiv;
    archiv=fopen("enteros.dat","wb");

    int carga;
    //CREAMOS ARCHIVO.
    cout<<"Ingrese valor (0 para cortar): ";
    cin>>carga;
    while(carga!=0){
        fwrite(&carga,sizeof(int),1,archiv);
        cout<<"Ingrese valor (0 para cortar): ";
        cin>>carga;

    }
    fclose(archiv); */


    //LEEMOS ARCHIVO 
    Nodo *lista=NULL;
    FILE *archiv;
    archiv=fopen("enteros.dat","rb");
    int aread;

    fread(&aread,sizeof (int),1,archiv);
    while(!feof(archiv)){ //Con esto insertarmos ordenado en la lista.
        insertarOrdenado(lista,aread);
        fread(&aread,sizeof (int),1,archiv);
    }
    fclose(archiv);

    archiv=fopen("enteros.dat","wb");
    //Debemos recorrer la lista para ir escribiendolo en el archivo.
    Nodo *aux=lista;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(int),1,archiv); //con aux->info, toma el valor entero.
        aux=aux->sgte;
    }
    fclose(archiv);
    mostrar(lista);
    liberar(lista);


    return 0;
}


void insertarOrdenado(Nodo *&Lista, int valor){

    Nodo *nuevo=new Nodo();
    
    nuevo->info=valor;
    nuevo->sgte=NULL;
    Nodo *aux=Lista; 
    Nodo *ant=NULL; 
    while(aux!=NULL && aux->info<valor){
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
        cout<<aux->info<<endl; 
        aux=aux->sgte; 
    }
}