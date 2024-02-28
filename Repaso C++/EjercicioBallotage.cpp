/* Dado un vector de Ballotage que indica los votos en la Argentina (24 provincias) por provincia para presidente.
El vector contiene el código de la provincia, código del partido político ('A' y 'B'), y la cantidad
de votos. Se sabe que el vector muestra por cada provincia y por cada partido los resultados, determinar:
a-¿Cuál es el total de voto recibios para el partido 'A'?
b-¿Cuál es el promedio de votos, por provincia, que recibió el partido 'B'?
c-¿Cuál es el máximo de votos recibidos y en qué provincia y para qué partido fue? */

#include<iostream>
#include<stdio.h>
using namespace std;

struct Prov{
    int codP;
    char partido;
    int cantV;
};


int main(){
    Prov vec[24];
    int len;

    for(int i;i<len;i++){
        cout<<"Ingrese el codigo de Provincia: "<<vec[i].codP<<endl;
        cout<<"Ingrese el partido politico (A o B): "<<vec[i].partido<<endl;
        cout<<"Ingrese cantidad de votos: "<<vec[i].cantV<<endl;
    }

    //PARTE A
    int totalVotosA=0;
    for(int i=0;i<len;i++){
        if(vec[i].partido=='A'){
            totalVotosA +=vec[i].cantV;
        }
    }
    cout<<"El total de votos del partido A es: "<<totalVotosA<<endl;

    //PARTE B
    int totalVotosB=0;
    int provinciaPartidoB=0;
    float promedioB;
    for(int i=0;i<len;i++){
        totalVotosB +=vec[i].cantV;
        provinciaPartidoB++;
    }
    promedioB=totalVotosB/provinciaPartidoB;
    cout<<"El promedio de votos del partido B es: "<<promedioB<<endl;


    //PARTE C
    

    return 0;
}