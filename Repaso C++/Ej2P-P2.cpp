/* Se tiene u archivo de productos STOCK.DAT (sin orden):
-Codigo de Producto: 999999999
-Peso: 9999kg
-Tipo: 'P o 'N' (Perecedero o No perecedero)
-Cantidad en Stock: 99999999
Se pide:
1) Ordenar el archivo STOCK.DAT por código de Producto.
2) Generar dos listas y mostrarlas por pantalla:
a-La primera con los productos que no tiene unidades en Stock.
b-La segunda con los productos PESADOS (pero mayor a 100kg) y No perecederos. */

#include<iostream>
#include<stdio.h>

using namespace std;

struct Prod{
    int codP;
    int peso;
    char tipo;
    int stock;
};

struct Nodo{
    Prod Info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, Prod Info){
    Nodo *nuevo=new Nodo();
    nuevo->Info=Info.codP;
    nuevo->Info=Info.peso;
    nuevo->Info=Info.stock;
    nuevo->Info=Info.tipo;
    nuevo->sgte=NULL;
    Nodo *aux=Lista;
    Nodo *ant=NULL;
    while(aux!=NULL && aux->Info.codP<Info.codP){
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

void agregarPrimero(Nodo *&Lista, Prod Info){
    Nodo *nuevo=new Nodo();
    nuevo->Info=Info.codP;
    nuevo->Info=Info.peso;
    nuevo->Info=Info.stock;
    nuevo->Info=Info.tipo;
    nuevo->sgte=Lista;
    Lista=nuevo;
}

void liberar(Nodo *&Lista){
    Nodo *aux;
    while(Lista!=NULL){
        aux=Lista;
        Lista=Lista->sgte;
        delete(aux);
    }
}

void mostrar(Nodo *&Lista){
    Nodo *aux=Lista;
    while(aux!=NULL){
        cout<<"Codigo de Producto: "<<aux->Info.codP<<endl;
        cout<<"Peso: "<<aux->Info.peso<<endl;
        cout<<"Tipo: "<<aux->Info.tipo<<endl;
        cout<<"Stock: "<<aux->Info.stock<<endl;
        aux=aux->sgte;
    }
}

int main(){

    FILE *arch=fopen("STOCK.DAT","rb");
    Prod auxA;

    Nodo *ListaA=NULL;
    Nodo *ListaB=NULL;
    Nodo *ListaC=NULL;

    fread(&auxA,sizeof(struct Prod),1,arch);
    while(!feof(arch)){
        insertarOrdenado(ListaA,auxA);
        if(auxA->Info.stock==0){
            agregarPrimero(ListaB,auxA);
        }
        else if((auxA->Info.peso>100) && (auxA->Info.tipo=='N')){
            agregarPrimero(ListaC,auxA);
        }
        fread(&auxA,sizeof(struct Prod),1,arch);
    }
    fclose(arch);


    FILE *arch=fopen("STOCK.DAT","wb");
    Nodo *auxLista=ListaA;
    while(auxLista!=NULL){
        fwrite(&auxLista->Info,sizeof(struct Prod),1,arch);
        auxLista=auxLista->ste;
    }
    fclose(arch);
    liberar(ListaA);

    mostrar(ListaB);
    liberar(ListaB);

    mostrar(ListaC);
    liberar(ListaC);

    return 0;
}