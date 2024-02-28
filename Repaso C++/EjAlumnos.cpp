/* Se tiene un vector de los alumnos del kurso K1151, que contiene todos los alumnos que se inscribieron
en la materi con los siguiente campos:
-Numero de Legajo
-Nota del Primer Parcial
-Nota del Segundo Parcial
Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Segundo parcial,
cada nodo de la lista contiene el Numero de Legajo y la nota del recuperatorio._
Se pide, actualizar el vector K1151 con la información que hay en la lista, SOLO para el campo Nota Segunda parcial si
es que aprobó el recuperatorio, sino no hacer nada.
Ej: Si un alumno obtuvo 6 o más en su recuperatorio (esto se encontrará en el nodo) en el vector en el campo de Nota del Primer Parcial,
tendrá que aparecer esa nueva nota. Si obtuvo menos que 6, no modificar.
Se sabe que cómo máximo hay 50 alunmnos */

#include<iostream>
#include<studio.h>
using namespace std;

struct Alum{
    int legajo;
    int p1;
    int p2;
};

struct Rec{
    int legajo;
    int rP2;
};

struct Nodo{
    Rec Info;
    Nodo *sgte;
};


int main(){

    Alum vec[50];
    int len;

    Alum raux;

    Nodo *Lista;
    Nodo *aux=Lista;
    while(aux!=NULL){
        int pos=buscar(vec,len,aux->Info.legajo);
        if(pos>-1){
            if(aux->Info.rP2>6){
                vec[pos].p2=aux->Info.rP2;
            }
        }
        aux=aux->sgte;
    }
    liberar(Lista);

    return 0;
}