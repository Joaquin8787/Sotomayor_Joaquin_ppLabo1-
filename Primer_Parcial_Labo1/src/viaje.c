/*
 * viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "viaje.h"

int arrayVacioViajes(eViaje aViajes[], int tamV){
    int retorno = 1;
    if(aViajes != NULL && tamV > 0){
        for(int i=0; i<tamV;i++){
        if(aViajes[i].isEmpty == 0){
            retorno = -1;
        }
    }
    }
    return retorno;
}

int altaViaje(eViaje aViajes[],int tamV,int* idViaje){
    int retorno = -1;
    int posicion;
    char seguir = 's';

     if(aViajes != NULL && idViaje != NULL &&tamV > 0){
         do{
    if(buscarLibreViaje(aViajes,tamV, &posicion) == 1){

        printf("Ingrese el nombre del viaje: \n");
        fflush(stdin);
        scanf("%[^\n]",aViajes[posicion].descripcion);
        aViajes[posicion].isEmpty = 0;
        aViajes[posicion].idViaje = *idViaje;
        (*idViaje)++;
        retorno = 1;
    }
    else{
        printf("No hay posiciones disponible para ingresar otr viaje");
    }
    printf("Desea ingresar otro viaje?: \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    } //IF Inicio
    return retorno;
}
int bajaViajes(eViaje aViajes[],int tamV){
    int retorno = -1;
    int idViaje;
    int posicion;
    char seguir = 's';
    if(aViajes != NULL && tamV > 0){
        do{
    mostrarViajes(aViajes,tamV);
    printf("\n Ingrese el id del viaje que quiere dar de baja: ");
    scanf("%d", &idViaje);
    posicion = buscarViajeId(aViajes,tamV,&idViaje);
    while(posicion == -1){
    	mostrarViajes(aViajes,tamV);
    	printf("\n ERROR. Ingrese el id del viaje que quiere dar de baja: ");
    	scanf("%d", &idViaje);
    	posicion = buscarViajeId(aViajes,tamV,&idViaje);
    }
       aViajes[posicion].isEmpty = 1;
       retorno = 1;
    printf("Desea dar de baja otro viaje? \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    }
    return retorno;
}
int buscarLibreViaje(eViaje aViajes[], int tamV, int* posicion){
    int retorno = -1;
    if(aViajes != NULL && posicion != NULL &&tamV > 0){
        for(int i=0; i<tamV;i++){
        if(aViajes[i].isEmpty == 1){
           *posicion = i;
            retorno = 1;
            break;
        }
    }
    }
    return retorno;
}
int buscarViajeId(eViaje aViajes[], int tamV, int* idViaje){
    int retorno = -1;
    if(aViajes!= NULL &&tamV >0){
         for(int i=0; i<tamV;i++){
        if(aViajes[i].idViaje == *idViaje && aViajes[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}


int mostrarViaje(int idViaje,int kms, eViaje aViajes[],int tamV)
{
    int retorno = -1;
    char descripcion[20];
    if(descripcion != NULL && aViajes != NULL){
    cargarDescripcionViajeDesdeId(idViaje,aViajes,tamV,descripcion);
    printf("%d              %-20s      %d  \n", idViaje, descripcion, kms);
    retorno = 1;
    }
  return retorno;
}

int mostrarViajes(eViaje aViajes[],int tamV)
{
    int retorno = -1;
    if(aViajes != NULL &&tamV >0){
    printf("idViaje    descripcion      kms\n");
    for(int i=0; i<tamV; i++)
    {
        if(aViajes[i].isEmpty == 0){
        mostrarViaje(aViajes[i].idViaje,
        aViajes[i].kms,
        aViajes,
        tamV);
        }
    }
    retorno = 1;
    }
    return retorno;
}
int cargarDescripcionViajeDesdeId(int idViaje,eViaje aViajes[], int tamV, char descripcion[]){
    int retorno = -1;
    if(aViajes != NULL && tamV > 0){
        for(int i=0; i<tamV;i++){
        if(idViaje == aViajes[i].idViaje){
          strcpy(descripcion,aViajes[i].descripcion);
          retorno = 1;
     }

    }
}
return retorno;
}
int mostrarIdViajeDesdeDescripcion(eViaje aViajes[],int tamV, char descripcion[]){
    int retorno = -1;
    if(aViajes != NULL && tamV > 0){
        for(int i=0; i<tamV;i++){
        if(strcmp(descripcion,aViajes[i].descripcion) == 0){
          retorno = aViajes[i].idViaje;
          break;
        }
    }
    }
    return retorno;
}

