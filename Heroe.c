#include <stdio.h>
#include <stdlib.h>
#include "Heroe.h"

void leerHeroe(Heroe *h){ //Aqui el usuario agrega nombre, vida, ataque del heroe y queda registrada
    printf("Ingresa el nombre de tu heroe: ");
    scanf("%s", h->nombre);
    printf("Ingresa la vida del heroe: ");
    scanf("%d", &(h->vida));
    printf("Ingresa el nivel de ataque: ");
    scanf("%d", &(h->ataque));
    printf("\n");
}

void imprime(Heroe *h){ //imprimimos al heroe y todas sus caracteristicas
    printf("*********************\n\n");
    printf("Nombre: %s\n", h->nombre);
    printf("Vida: %d\n", h->vida);
    printf("Ataque: %d\n", h->ataque);
    printf("\n");
}
