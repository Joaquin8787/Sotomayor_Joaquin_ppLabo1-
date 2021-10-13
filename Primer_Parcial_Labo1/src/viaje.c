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
    float auxKms;
    char auxDescripcion[TEXT_SIZE];
    char seguir = 's';

    if(aViajes != NULL && idViaje != NULL &&tamV > 0){
    do{
    if(buscarLibreViaje(aViajes,tamV, &posicion) == 1){

    if(joaquin_getString(auxDescripcion, "Ingrese el nombre del viaje: \n", "ERROR!!!\n", TEXT_SIZE, 2) == 1
    	&& joaquin_getNumeroFlotante(&auxKms,"Ingrese la cantidad de kms que recorre: ","ERROR!!!\n",80,5000,2) == 1){
    	 strcpy(aViajes[posicion].descripcion,auxDescripcion);
    	 aViajes[posicion].kms = auxKms;
    	 aViajes[posicion].isEmpty = 0;
    	 aViajes[posicion].idViaje = *idViaje;
    	 (*idViaje)++;
    	 retorno = 1;
    }
    }
    else{
        printf("No hay posiciones disponible para ingresar otro viaje");
    }
    joaquin_getCaracter(&seguir, "Desea dar de alta otro viaje? \n (s/n): ", "ERROR \n",'n','s', 2);
    }while(seguir == 's');
    }
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
    joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del viaje debe ser a partir del 100\n",100,1000,2);
    posicion = buscarViajeId(aViajes,tamV,&idViaje);
    //Valido
    while(posicion == -1){
    	printf("ERROR... El id ingresado no existe \n");
    	mostrarViajes(aViajes,tamV);
    	joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del viaje debe ser a partir del 100\n",100,1000,2);
    	posicion = buscarViajeId(aViajes,tamV,&idViaje);
    }
    joaquin_getCaracter(&confirmar, "Esta seguro que quiere eliminar este viaje?\n (s/n): ", "ERROR \n",'n','s', 2);
    if(confirmar == 's'){
    	aViajes[posicion].isEmpty = 1;
    	retorno = 1;
    }
    joaquin_getCaracter(&seguir, "Desea dar de alta otro viaje? \n (s/n): ", "ERROR \n",'n','s', 2);
    }while(seguir == 's');
    }
    return retorno;
}
int modificarViaje(eViaje aViajes[],int tamV){
    int retorno = -1;
    int posicion;
    int idViaje;
    int opcionSubMenu;
    char seguir = 's';
    if(aViajes != NULL && tamV > 0){
    do{
    	mostrarViajes(aViajes,tamV); //MUESTRO LOS VIAJES
    	joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del viaje debe ser a partir del 100\n",100,1000,2);
    	posicion = buscarViajeId(aViajes,tamV,&idViaje); //GUARDO EL INDICE EN POSICION
        while( posicion == -1){
    	printf("ERROR... El id ingresado no existe \n");
    	mostrarViajes(aViajes,tamV);
    	joaquin_getNumero(&idViaje,"Ingrese el id del viaje que quiere dar de baja: ", "ERROR. el id del viaje debe ser a partir del 100\n",100,1000,2);
    	posicion = buscarViajeId(aViajes,tamV,&idViaje);
    }
    opcionSubMenu= menuModificacionesV();
    if(opcionSubMenu == 1){
	if(joaquin_getString(aViajes[posicion].descripcion, "Ingrese el nombre de la marca: \n", "ERROR!!!\n", TEXT_SIZE, 2) == 1){
		printf("Modificacion exitosa!!! \n");
		retorno = 1;
	}
	else{
		printf("Hubo un error al modificar la descripcion del viaje\n");
	}
    }
    else if(opcionSubMenu == 2){
    	if(joaquin_getNumeroFlotante(&aViajes[posicion].kms,"Ingrese la cantidad de kms que recorre: ","ERROR!!!\n",80,5000,2)){

    	}
    	else{
    		printf("Hubo un error al modificar los kms del viaje\n");
    	}
    }
    joaquin_getCaracter(&seguir, "Desea dar modificar otra viaje? \n (s/n): ", "ERROR!!!\n",'n','s', 2);
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
    char descripcion[TEXT_SIZE];
    if(descripcion != NULL && aViajes != NULL){
    cargarDescripcionViajeDesdeId(idViaje,aViajes,tamV,descripcion);
    printf("%d        %-10s         %.2f  \n", idViaje, descripcion, kms);
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
    printf("idViaje    DESCRIPCION         KMS\n");
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

