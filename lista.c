#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "Heroe.h"

void iniciarLista(Lista *pLista, int tam) { //funcion que inicializa la lista
    pLista->tam = tam;
    pLista->inicio = NULL;
    pLista->fin = NULL;
}

int vacia(Lista *pLista) { //funcion que revisa que la lista este o no vacia
    if (pLista->inicio == NULL) {
        return 1;
    }
    return 0;
}

void agregarNodoFinal(Lista *pLista,void *pInfo) { //agregamos un nodo al final de lista (tipo cola)
     Nodo *pNodo;

     pNodo = crearNodo(pLista->tam,pInfo);
     if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
     }
     pLista->fin->siguiente = pNodo;
     pLista->fin = pNodo;
}

void agregarNodoInicio(Lista *pLista,void *pInfo) { //Agregamos los nodos al inicio de la lista (tipo pila)
    Nodo *pNodo;
    pNodo = crearNodo(pLista->tam,pInfo);
    if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
    }
    pNodo->siguiente = pLista->inicio;
    pLista->inicio = pNodo;

}

void recorre(Lista *pLista, void (operacion) (Heroe *h) ) { // Recorremos la lista nodo por nodo hasta que nodo apunte a null
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vacia!\n");
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }

}

void *retiraNodoInicio(Lista *pLista) { //Borramos el nodo que este en la posicion inicio de la lista
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    res = pLista->inicio->informacion;
    q = pLista->inicio;
    pLista->inicio = q->siguiente;
    free(q); q=NULL;
    return res;
}

void *retiraNodoFinal(Lista *pLista) { //Retiramos el nodo que en su propiedad siguiente apunte a NULL
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    q = pLista->inicio;
    while (q->siguiente!=pLista->fin) {
        q = q->siguiente;
    }
    res = pLista->fin->informacion;
    free(pLista->fin);
    q->siguiente = NULL;
    pLista->fin = q;
    return res;
}

void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) ){ //Buscamos un valor en la lista
    Nodo *pNodo;

    pNodo = pLista->inicio;
    while(pNodo != NULL){
        if(igualdad(valor, pNodo->informacion)==1)
            return pNodo->informacion;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}
void *retirarElPrimerValor(Lista *pLista,void *pInfo, int (igualdad) (void *d1,void *d2) ){ //Retiramos el valor que estamos buscando
    Nodo *pNodo;
    Nodo *pAnterior;
    void *res;
    if(vacia(pLista))
        return NULL;
    if(igualdad(pLista->inicio->informacion, pInfo))
        return retiraNodoInicio(pLista);
    if(igualdad(pLista->fin->informacion, pInfo))
        return retiraNodoFinal(pLista);
        pAnterior = pLista->inicio;
        pNodo = pLista->inicio->siguiente;
    while(pNodo != pLista->fin){
        if(igualdad(pNodo->informacion, pInfo)==1){
            pAnterior->siguiente = pNodo->siguiente;
            res = pNodo->informacion;
            free(pNodo);
            return res;
        }
        pAnterior = pNodo;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}

int agregarNodoAntesDe(Lista *pLista,void *clave, void *antes, int (igualdad) (void *d1,void *d2)) { //Si lo que queremos es poner un valor antes del que buscamos, lo agregamos gracias a esta funcion
    Nodo *pNodo;
    Nodo *pAnterior;
	if (vacia(pLista)) {
        return 0;
    }
	if(igualdad(pLista->inicio->informacion, antes)==1){
		agregarNodoInicio(pLista, clave);
		return 1;
}
 	pAnterior = pLista->inicio;
	pNodo = pLista->inicio->siguiente;
		while(pNodo!=NULL){
		if(igualdad(pNodo->informacion, antes)==1){
			pAnterior->siguiente = crearNodo(pLista->tam, clave);
			pAnterior->siguiente->siguiente = pNodo;
			return 1;
		}
		pAnterior = pNodo;
		pNodo = pNodo->siguiente;
}
	return 0;
}
void imprimirEntero(void *dato) { //Utilizamos esta para imprimir numeros enteros, no la ocupamos en esta practica
    int *x;
    x = (int *)dato;
    printf("%d\n",*x);
}
int comparaMayorVida(void *dato, Heroe *h) { //Primer dato mayor al segundo, comparamos las vidas de los personajes y retorna 1 si el primer dato es mayor al segundo, 0 si es menor.
    int *x, *y;
    x = &(h->vida);
    y = (int *)dato;
    if(*x>*y)
        return 1;
    return 0;
}
void menu() {
    printf("\n\n");
    printf("       MEN%c DE H%cROES\n", 233, 144);
    printf("(1) Agregar H%croe.\n", 130);
    printf("(2) Mostrar h%croes.\n", 130);
    printf("(3) Mostrar h%croes mayores a...\n", 130);
    printf("(4) H%croe A ataca a H%croe B\n", 130, 130);
    printf("(0) SALIR\n");
}

int leerOpcion() {
    int respuesta;
    do {
        menu();
        printf("%cCu%cl es tu elecci%cn? ", 168, 160, 162);
        scanf("%d",&respuesta);
        if (respuesta<0 || respuesta>4) {
            printf("Hay un error en tu elecci%cn!\n", 162);
            printf("Valores s%clo entre 0 y 5 por favor\n", 162);
        }
    } while(respuesta<0 || respuesta>4);
    printf("\n");
    return respuesta;

}
void recorreVidaMayor(Lista *pLista, void *d1, int (comparacion)(void *d1, Heroe *h), void (operacion) (Heroe *h) ) { // Recorremos la lista nodo por nodo hasta que nodo apunte a null
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vac%ca!\n", 161);
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        if(comparacion(d1, pNodo->informacion)==1)
        operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }
}
//regresa un valor igual a 1 si son iguales
//regresa un valor igual a 0 si no son iguales

/*
int comparaMayorVida(void *dato, Heroe *h) { //Primer dato mayor al segundo
    int *x, *y;
    x = &(h->vida);
    y = (int *)dato;
    if(*x>*y)
        return 1;
    return 0;
}

int comparaNombre(void *dato, Heroe *h) { //Primer dato mayor al segundo
    int *x, *y;
    x = &(h->vida);
    y = (int *)dato;
    if(*x>*y)
        return 1;
    return 0;
}
    int ConfirmarHeroe(void *personaje, Heroe *h2){
    char *x, *y;
    x = (char *)nombre);
    y = &(h2->nombre);
    if (strcmp(*x, *y) == 0)
        return 1;
    return 0;
}
    void *buscarAyB(Lista *pLista,void *valor, int (BuscarNombre) (void *d1,void *d2) ){
    Nodo *pNodoA;
    Nodo *pNodoB;
    pNodoA = pLista->inicio;
    while(pNodoA != NULL || pNodoB != NULL){
        if(BuscarA(atacante, pNodoA->informacion)==1 || confirmar(atacado, pNodoB->informacion))
            return pNodoA->informacion;
            return pNodoB->informacion;
        pNodoA = pNodoA->siguiente;
        pNodoB = pNodoB->siguiente;
    }
    return NULL;
}
    void *buscarB(Lista *pLista,void *valor, int (BuscarNombre) (void *d1,void *d2) ){
    Nodo *pNodoB;

    pNodoB = pLista->inicio;
    while(pNodoB != NULL){
        if(BuscarB(atacante, pNodoB->informacion)==1)
            return pNodoB->informacion;
        pNodoB = pNodoB->siguiente;
    }
    return NULL;
}
void pelea(Heroe *h1, Heroe *h2){
    int *a, *b;
    a = &(h->ataque);
    b = &(h->vida);
    *b = *b - *a;
    return *b;
}
int ConfirmarHeroe(void *nombre, Heroe *h2){
    char *x, *y;
    x = (char *)nombre;
    y = &(h2->nombre);
    if (strcmp(*x, *y) == 0)
        return 1;
    return 0;
}
void pelea(Heroe *h1, Heroe *h2){
    int *a, *b;
    a = &(h1->ataque);
    b = &(h2->vida);
    *b = *b - *a;
    return *b;
}
*/
