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
#include "joaquin.h"

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
    char auxDescripcion[20];
    char seguir = 's';

    if(aViajes != NULL && idViaje != NULL &&tamV > 0){
    do{
    if(buscarLibreViaje(aViajes,tamV, &posicion) == 1){

    if(joaquin_getNombre(auxDescripcion, "Ingrese el nombre del viaje: \n", "ERROR, tipo de dato no valido\n", 20, 2) == 0){
    	 aViajes[posicion].isEmpty = 0;
    	 aViajes[posicion].idViaje = *idViaje;
    	 (*idViaje)++;
    	 retorno = 1;
    }
    }
    else{
        printf("No hay posiciones disponible para ingresar otr viaje");
    }
    joaquin_getCaracter(&seguir, "Desea dar de alta otro viaje? \n (s/n): ", "ERROR \n",'s','n', 2);
    }while(seguir == 's');
    } //IF Inicio
    return retorno;
}
int bajaViajes(eViaje aViajes[],int tamV){
    int retorno = -1;
    int idViaje;
    int posicion;
    char confirmar;
    char seguir = 's';
    if(aViajes != NULL && tamV > 0){
        do{
    mostrarViajes(aViajes,tamV);
    joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del avion debe ser a partir del 100",100,1000,2);
    posicion = buscarViajeId(aViajes,tamV,&idViaje);
    //Valido
    while(posicion == -1){
    	mostrarViajes(aViajes,tamV);
    	joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del avion debe ser a partir del 100",100,1000,2);
    	posicion = buscarViajeId(aViajes,tamV,&idViaje);
    }
    joaquin_getCaracter(&confirmar, "Esta seguro que quiere eliminar esta marca?\n (s/n): ", "ERROR \n",'s','n', 2);
    if(confirmar == 's'){
    	aViajes[posicion].isEmpty = 1;
    	retorno = 1;
    }
    joaquin_getCaracter(&seguir, "Desea dar de alta otro viaje? \n (s/n): ", "ERROR \n",'s','n', 2);
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


int mostrarViaje(int idViaje,float kms, eViaje aViajes[],int tamV)
{
    int retorno = -1;
    char descripcion[20];
    if(descripcion != NULL && aViajes != NULL){
    cargarDescripcionViajeDesdeId(idViaje,aViajes,tamV,descripcion);
    printf("%d              %-20s      %.2f  \n", idViaje, descripcion, kms);
    retorno = 1;
    }
  return retorno;
}

int mostrarViajes(eViaje aViajes[],int tamV)
{
    int retorno = -1;
    if(aViajes != NULL &&tamV >0){
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("idViaje    descripcion      kms\n");
    for(int i=0; i<tamV; i++)
    {
        if(aViajes[i].isEmpty == 0){
        mostrarViaje(aViajes[i].idViaje,
        aViajes[i].kms,
        aViajes,
        tamV);
        retorno = 1;
        }
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
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

