/* Se tiene un archivo de disponibilidad de pasajes en tren Viajes2024.dat(sin orden):
-ID del tramo
-Tipo de Reserva: 'P', 'E' o 'S'
-Precio
Se pide:
a) Order el archivo Viajes2024.DAT por ID del tramo.
b) Armar una lista y mostrarla por pantalla, ordenada por precio, si el tipo de reserva es 'P'o 'E'
y el precio supera los $2500.
Nota: Solo se puede leer 1 vez el archivo. */

#include<iostream>
#include<stdio.h>
using namespace std;

struct Pasajes{
    int iD;
    char tipo;
    int precio;
};

struct Nodo{
    Pasajes Info;
    Nodo *sgte;
};



int main(){

    FILE *arhiv;
    archiv=fopen("Viajes2024.Dat","rb");

    Pasajes aux;

    Nodo *ListaA=NULL;
    Nodo *ListaB=NULL;

    Nodo *auxA=ListaA;
    Nodo *auxB=ListaB;
    
    fread(&aux,sizeof(struct Pasajes),1,archiv);
    while(!feof(archiv)){
        insertarOrdenado(ListaA,aux); //lista para ordernar el archivo
        insertarOrdenado(ListaB,aux); //lista orden de precio.
        fread(&aux,sizeof(struct Pasajes),1,archiv);
    }
    fclose(archiv);

    archiv=fopen("Viajes2024.Dat","wb");
    while(auxA!=NULL){
        fwrite(&auxA->Info,sizeof(struct Pasajes),1,archiv);
        auxA=auxA->sgte;
    }
    fclose(archiv);
    liberar(ListaA);

    
    archiv=fopen("Viajes2024.Dat","wb");
    while(auxB!=NULL){
        if(auxB->Info.tipo == 'E' || auxB->Info.tipo == 'P' && auxB->Info.precio>2500){
            fwrite(&auxB->Info,sizeof(struct Pasajes),1,archiv);

        }
        auxB=auxB->sgte;
    }
    fclose(archiv);
    mostrar(ListaB);
    liberar(ListaB);

    return 0;
}