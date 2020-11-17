#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Heroe.h"
#include "nodo.h"

struct lista { //definimos la estructura tipo lista con tamaño, y dos nodos de inicio y fin
    int tam;
    Nodo *inicio;
    Nodo *fin;
};

typedef struct lista Lista; //decimos que queremos una Lista del tipo struct lista

void iniciarLista(Lista *pLista,int tam);
int vacia(Lista *pLista);
void agregarNodoFinal(Lista *pLista,void *pInfo);
void agregarNodoInicio(Lista *pLista,void *pInfo);
void recorre(Lista *pLista, void (operacion) (Heroe *h));
void *retiraNodoInicio(Lista *pLista);
void *retiraNodoFinal(Lista *pLista);
void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) );
void *retirarNodoFinal(Lista *pLista,void *clave, int (igualdad) (void *d1,void *d2) );
void *retirarElPrimerValor(Lista *pLista,void *pInfo, int (igualdad) (void *d1,void *d2) );
int agregarNodoAntesDe(Lista *pLista, void *clave, void *antes, int (igualdad)(void *d1, void *d2));
void recorreVidaMayor(Lista *pLista, void *d1, int (comparacion)(void *d1, Heroe *h), void (operacion) (Heroe *h) );
int comparaMayorVida(void *dato, Heroe *h);
int leerOpcion();
void menu();

#endif // LISTA_H_INCLUDED
