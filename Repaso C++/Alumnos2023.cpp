#include<iostream>
#include<stdio.h>

using namespace std;

struct Alumno{
    int legajo;
    int dni;
    int P1;
    int P2;
};

//Funcion para inicializar vector.
void inicializar(Alumno vec[],int cantP,Alumno valorInicial){
    for(int i=0;i<cantP;i++){
        vec[i].legajo=valorInicial.legajo;
        vec[i].dni=valorInicial.dni;
        vec[i].P1=valorInicial.P1;
        vec[i].P2=valorInicial.P2;
    }
}

//va Alumno valor pues tenemos un registro.
void insertar(Alumno vec[], int & len, Alumno valorInicial, int pos){
    for(int i=len;i>pos;i--){
        vec[i].legajo=vec[i-1].legajo;
        vec[i].dni=vec[i-1].dni;
        vec[i].P1=vec[i-1].P1;
        vec[i].P2=vec[i-1].P2;

    }
    vec[pos].legajo=valorInicial.legajo;
    vec[pos].dni=valorInicial.dni;
    vec[pos].P1=valorInicial.P1;
    vec[pos].P2=valorInicial.P2;
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
    
    Alumno vec[10];
    int len=0;

    //Inicializamos los campos del vector en 0.
    Alumno valorInicial;
    valorInicial.legajo=0;
    valorInicial.dni=0;
    valorInicial.P1=0;
    valorInicial.P2=0;

    //Invocamos la función de inicializar el vector.
    inicializar(vec,10,valorInicial); //valorInicial es un registro con 0.

    //Abrimos el archivo para leer.
    FILE *Alums=fopen("AlumnosArchiv.data","rb");
    Alumno raux;
    fread(&raux,sizeof(struct Alumno),1,Alums);
        //&vec[1]
    while(!feof(Alums)){
        //llamamos al insertado ordenado de vector.
        insertarOrdenado(vec,len,raux);

        fread(&raux,sizeof(struct Alumno),1,Alums); //necesitamos los datos nuevos, NO olvidar.
    }
    fclose(Alums);


    //____________________________________________________________________________
    //ESCRITURA

    //Abrimos el archivo para escribir.
    Alums=fopen("AlumnosArchiv.data","wb");

    //Voy a sobreescribir mi archivo.
    for(int i=0;i<len;i++){
        cout<<"Ingrese legajo:";
        cin>>vec[i].legajo;
        cout<<"Ingrese DNI:";
        cin>>vec[i].dni;
        cout<<"Ingrese Primer Nota:";
        cin>>vec[i].P1;
        cout<<"Ingrese Segunda Nota:";
        cin>>vec[i].P2;
        fwrite(&vec[i],sizeof(struct Alumno),1,Alums);
    }
    fclose(Alums);



    return 0;
}