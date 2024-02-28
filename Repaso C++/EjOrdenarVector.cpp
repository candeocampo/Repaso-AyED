// Se tiene un archivo de peliculas infantiles en una plataforma digital con los titulos
// disponibles para la Argentina. El archivo se llama "infatil.dat"
// Cod Pelicula: 999999
// Cant de Opiniones Positivas: 999999
// Cantidad de Vistas: 999999

//Se pide:
//a) Ordenar el archivo por opiniones positivas.
//b) Listar las 10 peliculas más vistas tuvieron tal listar incluir toda la información
// referente a la  
// Nota: sólo debe leer 1 vez en el archivo. 
// Se sabe que no hay más de 50 pelis.

#include<iostream>
#include<stdio.h>
using namespace std;

struct pelicula{
    int codP;
    int cantOp;
    int cantVis;
};

void inicializar(pelicula vec[],int cantP, pelicula valorIni){
    for(int i=0;i<cantP;i++){
        vec[i].codP=valorIni.codP;
        vec[i].cantOp=valorIni.cantOp;
        vec[i].cantVis=valorIni.cantVis;
    }
}



void insertar(pelicula vec[], int & len, pelicula valorInicial, int pos){
    for(int i=len;i>pos;i--){
        vec[i].codP=vec[i-1].codP;
        vec[i].cantOp=vec[i-1].cantOp;
        vec[i].cantVis=vec[i-1].cantVis;
    }
    vec[pos].codP=valorInicial.codP;
    vec[pos].cantOp=valorInicial.cantOp;
    vec[pos].cantVis=valorInicial.cantVis;
    len++;
}

void insertarOrdenado(Alumno vec[],int & len, Alumno valorInicial){
    //1) Dónde voy a cargar el valor.
    int i=0;
    while(i<len && vec[i].legajo<=valorInicial.legajo){
        i++;
    }
    //2) Cargar el vector.
    if(i==len){
        vec[len].legajo=valorInicial.legajo;
        vec[len].dni=valorInicial.dni;
        vec[len].P1=valorInicial.P1;
        vec[len].P2=valorInicial.P2;
        len++;
    }
    else{
        insertar(vec,len,valorInicial,i);
    }
}

int main(){

    pelicula vecA[50];
    int lenA=0; //acá va con 0 pues estamos inicializando el vector, el ej lo pide.
    //para el punto A, necesitamos crear un vector.

    pelicula vecB[50];
    int lenB=0;

    pelicula ini;
    ini.codP=0;
    ini.cantOp=0;
    ini.cantVis=0;

    inicializar(vecA,50,ini);
    inicializar(vecB,50,ini);


    //Leer archivo.
    FILE *titulos=fopen("infantil.dat","rb");
    pelicula raux; //definimos un registro aux.
    fread(&raux,sizeof(struct pelicula),1,titulos);
    while(!feof(titulos)){
        insertarOrdenado(vecA,lenA,raux);
        insertarOrdenado(vecB,lenB,raux);
        fread(&raux,sizeof(struct pelicula),1,titulos);
    }
    fclose(titulos);

    for(int i=0;i<10;i++){
        cout<<"Codigo: "<<vecB[i].codP;
        cout<<"Opiniones Positivas: "<<vecB[i].cantOp;
        cout<<"Vistas: "<<vecB[i].cantVis;
    }

    return 0;
}

