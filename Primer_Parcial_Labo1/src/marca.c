/*
 * marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"

int arrayVacioMarcas(eMarca aMarcas[], int tamM){
    int retorno = 1;
    if(aMarcas != NULL && tamM > 0){
        for(int i=0; i<tamM;i++){
        if(aMarcas[i].isEmpty == 0){
            retorno = -1;
        }
    }
    }
    return retorno;
}
int altaMarca(eMarca aMarcas[],int tamM,int* idMarcas){
    int retorno = -1;
    int posicion;
    char seguir = 's';

     if(aMarcas != NULL && idMarcas != NULL &&tamM > 0){
         do{
    if(buscarLibreMarca(aMarcas,tamM, &posicion) == 1){

        printf("Ingrese el nombre de la marca: \n");
        fflush(stdin);
        scanf("%[^\n]",aMarcas[posicion].descripcion);
        aMarcas[posicion].isEmpty = 0;
        aMarcas[posicion].id = *idMarcas;
        (*idMarcas)++;
        retorno = 1;
    }
    else{
        printf("No hay posiciones disponible para ingresar otra marca");
    }
    printf("Desea ingresar otra marca?: \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    } //IF Inicio
    return retorno;
}
int bajaMarcas(eMarca aMarcas[],int tamM){
    int retorno = -1;
    int idMarcas;
    int posicion;
    char seguir = 's';
    if(aMarcas != NULL && tamM > 0){
        do{
    mostrarMarcas(aMarcas,tamM);
    printf("\n Ingrese el id de la marca que quiere dar de baja: ");
    scanf("%d", &idMarcas);
    posicion = buscarMarcaId(aMarcas,tamM,&idMarcas);
    while(posicion == -1){
    	mostrarMarcas(aMarcas,tamM);
    	printf("\n Ingrese el id de la marca que quiere dar de baja: ");
    	scanf("%d", &idMarcas);
    	posicion = buscarMarcaId(aMarcas,tamM,&idMarcas);
    }
       aMarcas[posicion].isEmpty = 1;
       retorno = 1;
    printf("Desea dar de baja otra marca? \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    }
    return retorno;
}
int buscarLibreMarca(eMarca aMarcas[], int tamM, int* posicion){
    int retorno = -1;
    if(aMarcas != NULL && posicion != NULL &&tamM > 0){
        for(int i=0; i<tamM;i++){
        if(aMarcas[i].isEmpty == 1){
           *posicion = i;
            retorno = 1;
            break;
        }
    }
    }
    return retorno;
}
int buscarMarcaId(eMarca aMarcas[], int tamM, int* idMarcas){
    int retorno = -1;
    if(aMarcas!= NULL &&tamM >0){
         for(int i=0; i<tamM;i++){
        if(aMarcas[i].id == *idMarcas && aMarcas[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}

int mostrarMarca(int idMarca,eMarca aMarcas[],int tamM)
{
    int retorno = -1;
    char descripcion[20];
    if(descripcion != NULL && aMarcas != NULL){
    cargarDescripcionMarcaDesdeId(idMarca,aMarcas,tamM,descripcion);
    printf("%d              %-20s \n", idMarca, descripcion);
    retorno = 1;
    }
  return retorno;
}

int mostrarMarcas(eMarca aMarcas[],int tamM)
{
    int retorno = -1;
    if(aMarcas != NULL &&tamM >0){
        printf("idMarca    descripcion \n");
    for (int i=0; i<tamM; i++)
    {
        if(aMarcas[i].isEmpty == 0){
        mostrarMarca(aMarcas[i].id, aMarcas,tamM);
        }
    }
    retorno = 1;
    }
    return retorno;
}
int cargarDescripcionMarcaDesdeId(int idMarca,eMarca aMarcas[], int tamM, char descripcion[]){
    int retorno = -1;
    if(aMarcas != NULL && tamM > 0){
        for(int i=0; i<tamM;i++){
        if(idMarca == aMarcas[i].id){
          strcpy(descripcion,aMarcas[i].descripcion);
          retorno = 1;
     }

    }
}
return retorno;
}
int mostrarIdMarcaDesdeDescripcion(eMarca aMarcas[],int tamM, char descripcion[]){
    int retorno = -1;
    if(aMarcas != NULL && tamM > 0){
        for(int i=0; i<tamM;i++){
        if(strcmp(descripcion,aMarcas[i].descripcion) == 0){
          retorno = aMarcas[i].id;
          break;
        }
    }
    }
    return retorno;
}
