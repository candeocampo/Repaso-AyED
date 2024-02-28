#include<iostream>
#include<stdio.h>
using namespace std;



// -----------------------------------  ejercicio 1  ----------------------------------------------
// a)
int Promedio_Notas(int nota1, int nota2, int nota3)
{
    int suma = nota1 + nota2 + nota3;

    return (suma / 3);
}
// b)
void Vector_Ordenado(int vec[])
{
    int valor;
    cout << "Ingrese un valor: ";
    cin >> valor;

    while (valor != 0)
    {
        insertarOrdenado(vec; valor);
    }
}

// -----------------------------------  ejercicio 2  ----------------------------------------------
struct Nodo
{
    int dato;
    Nodo *sgte;
};

// a)
Nodo ListaOrd(Nodo *cfte1, Nodo *cfin1, Nodo *cfte2, Nodo *cfin2)
{
    Nodo lista = NULL;
    int carga;

    while (cfte1 != NULL)
    {
        carga = suprimir(cfte1, cfin1);
        insertar_Ordeando(lista, carga);
    }
    while (cfte2 != NULL)
    {
        carga = suprimir(cfte2, cfin2);
        insertar_Ordeando(lista, carga);
    }

    return lista;
}
// b)
void Interseccion(Nodo *cfte, Nodo *cfin, Nodo *lista1, Nodo *&lista2)
{
    Nodo *aux = lista1;
    Nodo *Encontrado = NULL;
    int carga;

    while (aux != NULL)
    {
        carga = suprimir(cfte, cfin);
        Encontrado = buscar(lista1, carga);

        if (Encontrado != NULL)
        {
            agregarPrimero(lista2, carga);
        }

        aux = aux->sgte;
    }
}

// -----------------------------------  ejercicio 3  ----------------------------------------------
#include <iostream>
using namespace std;

struct Ballotage
{
    int cod_Provincia;
    char cod_Partido; // A y B
    int cant_Votos;
};

// a)
int Total_Votos(Ballotage vec[])
{
    int suma = 0;

    for (int i = 0; i < 48; i++)
    {
        if (vec[i].cod_Partido == 'A')
        {
            suma += vec[i].cant_Votos;
        }
    }

    return suma;
}

// b)
int Promedio(Ballotage vec[])
{
    int suma = 0;

    for (int i = 0; i < 48; i++)
    {
        if (vec[i].cod_Provincia == 'B')
        {
            suma += vec[i].cant_Votos;
        }
    }
    return (suma / 24);
}

// c)
void Maximo_Votos(Ballotage vec[])
{
    int posMax = 0;

    for (int i = 1; i < 48; i++)
    {
        if (vec[posMax].cant_Votos < vec[i].cant_Votos)
        {
            posMax = i;
        }

        cout << "La provincia " << posMax << " obtubo el maximo de votos que son " << vec[posMax].cant_Votos << " y fue el partido " << vec[posMax].cod_Partido << endl;
    }
}

int main(int argc, char const *argv[])
{
    Ballotage vector[48];

    int total_votosA = Total_Votos(vector);
    cout << "Total de votos recibidos del partido A: " << total_votosA;

    int Promedio_VotosB = Promedio(vector);
    cout << "Promedio de votos recibidos del partido B : " << Promedio_VotosB;

    Maximo_Votos(vector);

    return 0;
}

// -----------------------------------  ejercicio 4  ----------------------------------------------
#include <iostream>
using namespace std;

struct Cabaña_Patagonia
{
    int cod_cabaña;
    int cant_reservas;
    int cant_huesped;
    float monto;
};
struct Reserva
{
    int cod_cabaña;
    char beneficio_turismo; // 'S' o 'N'
    int cant_huesped;
    float monto;
};
struct Nodo
{
    Reserva dato;
    Nodo *sgte;
};

int buscar(Cabaña_Patagonia vec[], int len, int valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    Cabaña_Patagonia vector[100];
    int len;

    Nodo *lista;
    Nodo *aux = lista;
    int pos;

    while (aux != 0)
    {
        pos = buscar(vector, len, aux->dato.cod_cabaña);

        if (aux->dato.beneficio_turismo == 'S')
        {
            vector[pos].cant_huesped = vector[pos].cant_huesped + aux->dato.cant_huesped;
            vector[pos].cant_reservas++;
            vector[pos].monto = vector[pos].monto + aux->dato.monto;
        }
        aux = aux->sgte;
    }
    liberar(lista);

    return 0;
}

// -----------------------------------  ejercicio 5  ----------------------------------------------
#include <iostream>
#include <stdio.h>
using namespace std;

struct PasajeTren
{
    int ID_Tramo;
    char tipo_reserva; // 'P' ; 'E' ; 'S'
    double precio;
};
struct Nodo
{
    PasajeTren dato;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, PasajeTren valor);
void liberar(Nodo *&lista);
void mostrar(Nodo *lista);

int main(int argc, char const *argv[])
{
    // Ordenar archivo Viajes2024.dat por ID tramo
    FILE *viaje = fopen("Viajes2024.dat", "rb");

    PasajeTren raux;
    Nodo *listaA = NULL;
    Nodo *listaB = NULL;

    fread(&raux, sizeof(struct PasajeTren), 1, viaje);
    while (!feof(viaje))
    {
        insertarOrdenado(listaA, raux); // ordenar por ID tramo
        insertarOrdenado(listaB, raux); // crear lista ordeanda por precio
    }

    Nodo *aux = listaB;
    while (aux != NULL)
    {
        if (aux->dato.tipo_reserva == 'P' || aux->dato.tipo_reserva == 'E' && aux->dato.precio > 2500)
        {
            mostrar(listaB);
        }
    }
    liberar(listaB);

    // escribimos el archivo ordenado
    aux = listaA;
    while (aux != NULL)
    {
        fwrite(&aux->dato, sizeof(struct PasajeTren), 1, viaje);
        aux = aux->sgte;
    }
    fclose(viaje);
    liberar(listaA);

    return 0;
}