#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "Heroe.h"

int main(){

    Heroe unHeroe; //Creamos una estructura del tipo Heroe y le asignamos el nombre de unHeroe
    Lista misHeroes; //Creamos una estructura de tipo Lista doned estaran todos los heroes
    iniciarLista(&misHeroes, sizeof(Heroe));
    int k, opcion;
    //char atacante[100], atacado[100];

    do {
        opcion = leerOpcion(); /*definimos la existencia */
        switch (opcion) {
            case 1: printf("Agregar H%croe:\n", 130);
                leerHeroe(&unHeroe); //Leemos heroe y lo que recibe es la direccion de unHeroe
                agregarNodoInicio(&misHeroes, &unHeroe); //Despues de leerlo agregamos el heroe al inicio de la lista
                break;
            case 2: printf("MOSTRANDO H%cROES\n", 144);
                recorre(&misHeroes, imprime); //recorremos la lista de misHeroes y los imprimimos
                break;
            case 3:
                printf("Mostrar h%croes mayor a...", 130);
                printf("H%croes mayor a: ", 130); //Preguntamos al usuario a partir de que nivel de vida quiere ver los heroes
                scanf("%d", &k); //Le asignamos el nivel de vida a k
                printf("\nEstos son los h%croes arriba de %d de vida:\n", 130,k);
                recorreVidaMayor(&misHeroes, &k,  comparaMayorVida, imprime);//ImprimeMayoresA(&misHeroes, &unHeroe, &k, comparaMayorVida, imprime));
                break;
            case 4: printf("Aqu%c se van a pelear\n", 161);
                break;
            case 0: printf("Hasta luego\n");
               break;
            default: printf("Opci%cn no reconocida %d\n", 163, opcion);
               break;
        }
    } while(opcion != 0);
    return 0;
}
/*
cosas por hacer:
    a) agregar héroe
    b) listar los heores
    c) lista los heroes mayor a
    d) heroe A ataca a heroe B
        B.vida = B.vida - A.ataque
        Si vida <=0 sale de la lista

    printf("Heroe A ataca a Heroe B\n");
    printf("Heroe A: ");
    scanf("%s", &atacante)
    printf("Heroe B: ");
    scanf("%s", &atacado);

    pelea(Heroe *h1, Heroe *h2){
        int *a, *b;

    }
    Batalla(comparaNombre(char *atacante))

    int ConfirmarHeroe(void *nombre, Heroe *h2){
    char *x, *y;
    x = (char *)nombre;
    y = &(h2->nombre);
    if (strcmp(*x, *y) == 0)
        return 1;
    return 0;
}
    Nodo *pNodoA;
    pNodoA= *(misHeroes)->inicio;
    while(pNodoA != NULL){
        if(ConfirmarHeroe(atacante, pNodoA->informacion)==1)
            return pNodoA->informacion;
        pNodoA = pNodoA->siguiente;
    }
    return 0;

    Nodo *pNodoB;
    pNodoB = *(misHeroes)->inicio;
    while(pNodoB != NULL){
        if(ConfirmarHeroe(atacante, pNodoB->informacion)==1)
            return pNodoB->informacion;
        pNodoB = pNodoB->siguiente;
    }
    return 0;
    recorre(&misHeroes, pelea(pNodoA->informacion, pNodoB->informacion));
    imprime(&misHeroes);

    printf("Heroe A ataca a Heroe B\n");
    printf("Heroe A: ");
    scanf("%s", &atacante);
    printf("Heroe B: ");
    scanf("%s", &atacado);

*/
