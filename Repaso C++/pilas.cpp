#include<iostream>
#include<stdio.h>

using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void push(Nodo *&pila,int valor); 
int pop(Nodo *&pila);

int main(){

    //definición de pila.
    Nodo *pila=NULL; //La iniciamos en NULL.
    int carga;

    //INGRESO POR USUARIO
    cout<<"Ingrese los valores(0 para cortar): "<<endl;
    cin>>carga;
    while(carga!=0){
        push(pila,carga);
        cout<<"Ingrese los valores(0 para cortar): "<<endl;
        cin>>carga;
    }
    
    //INGRESO MANUAL
    push(pila,5);
    push(pila,4);
    push(pila,2);

    int resultado;

    while(pila!=NULL){
        resultado=pop(pila);
        cout<<resultado<<endl;
    }


    return 0;
}

//Agg elementos a la pila.
void push(Nodo *&pila,int valor){
    Nodo *nuevo=new Nodo();   //1) Creamos el nodo nuevo: pedimos memoria
    nuevo->info=valor;        //2) Cargamos el nodo.
    nuevo->sgte=pila;         
    pila=nuevo;               //3) Conectar.
}


//Saca elementos de la pila -> Tinfo (devieñve el tInfo)
// 1) Debo quedarme con el valor de retorno.
//2 ) Devolver el espacio de memoria.
int pop(Nodo *&pila){

    int ret; //1) Guardar el valor de retorno.
    ret=pila->info;
    //2) Devolvemos memoria.
    Nodo *aux=pila;
    pila=aux->sgte; //o pila=pila->sgte;
    //Eliminación del nodo que devolvi -> liberar memoria.
    delete aux;
    return ret;
}