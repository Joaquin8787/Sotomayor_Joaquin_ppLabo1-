/*
 * avion.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "joaquin.h"
#include "avion.h"

int inicializarArrayAviones(eAvion aAviones[], int tamA){
    int retorno = -1;
    if(aAviones != NULL &&tamA > 0){
        for(int i = 0; i <tamA;i++){
        aAviones[i].idAvion = 0;
        aAviones[i].idViaje = 0;
        aAviones[i].idMarca = 0;
        aAviones[i].modelo = 0;
        aAviones[i].cantAsientos = 0;
        aAviones[i].matricula = 0;
        aAviones[i].isEmpty = 1;
        retorno = 1;
    }
    }
    return retorno;
}
int arrayVacioAvion(eAvion aAviones[], int tamA){
    int retorno = 1;
    if(aAviones != NULL && tamA > 0){
        for(int i=0; i<tamA;i++){
        if(aAviones[i].isEmpty == 0){
            retorno = -1;
        }
    }
    }
    return retorno;
}
int buscarLibreAvion(eAvion aAviones[], int tamA, int* posicion){
    int retorno = -1;
    if(aAviones != NULL && posicion != NULL &&tamA > 0){
        for(int i=0; i<tamA;i++){
        if(aAviones[i].isEmpty == 1){
           *posicion = i;
            retorno = 1;
            break;
        }
    }
    }
    return retorno;
}

int altaAviones(eAvion aAviones[],int tamA,int* idAvion,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM){
	 int retorno = -1;
	    int posicion;
	    int idAuxV;
	    int idAuxM;
	    int auxModelo;
	    int auxMatricula;
	    int auxCantAsientos;
	    char auxViaje[20];
	    char auxMarca[20];
	    char seguir = 's';

	     if(aAviones != NULL && idAvion != NULL &&tamA > 0){
	         do{
	    if(buscarLibreAvion(aAviones,tamA, &posicion) == 1){
	    	mostrarViajes(aViajes,tamV);
	    	printf("Ingrese el nombre del viaje que realiza: \n");
	        fflush(stdin);
	        scanf("%[^\n]",auxViaje);
	        idAuxV = mostrarIdViajeDesdeDescripcion(aViajes,tamV, auxViaje);
	        while(idAuxV == -1){
	        mostrarViajes(aViajes,tamV);
	        printf("ERROR. Ingrese el nombre del viaje que realiza: \n");
	        fflush(stdin);
	        scanf("%[^\n]",auxViaje);
	        idAuxV = mostrarIdViajeDesdeDescripcion(aViajes,tamV, auxViaje);
	        }
	        aAviones[posicion].idViaje = idAuxV;

	        mostrarMarcas(aMarcas,tamM);
	        printf("Ingrese el nombre de la marca del avion: \n");
	        fflush(stdin);
	        scanf("%[^\n]",auxMarca);
	        idAuxM = mostrarIdMarcaDesdeDescripcion(aMarcas,tamM, auxMarca);
	        while(idAuxV == -1){
	        mostrarMarcas(aMarcas,tamM);
	        printf("ERROR. Ingrese el nombre de la marca del avion: \n");
	        fflush(stdin);
	        scanf("%[^\n]",auxMarca);
	        idAuxM = mostrarIdMarcaDesdeDescripcion(aMarcas,tamM, auxMarca);
	       }
	        aAviones[posicion].idMarca = idAuxM;
	        joaquin_getNumero(&auxModelo,"Ingrese el modelo del avion: ", "ERROR. Ingrese el modelo del avion: ",1,1000,2);
	        joaquin_getNumero(&auxMatricula,"Ingrese la matricula del avion: ", "ERROR. Ingrese la matricula del avion: ",1,1000,2);
	        joaquin_getNumero(&auxCantAsientos,"Ingrese la cantidad de asientos que tiene el avion: ", "ERROR. Ingrese la cantidad de asientos que tiene el avion: ",1,1000,2);
	        aAviones[posicion].modelo = auxModelo;
	        aAviones[posicion].matricula = auxMatricula;
	        aAviones[posicion].cantAsientos = auxCantAsientos;

	        aAviones[posicion].isEmpty = 0;
	        aAviones[posicion].idAvion = *idAvion;
	        (*idAvion)++;
	        retorno = 1;
	    }
	    else{
	        printf("No hay posiciones disponible para ingresar otro intrumento");
	    }
	    printf("Desea ingresar otro intrumento?: \n");
	    fflush(stdin);
	    scanf("%c", &seguir);
	    }while(seguir == 's');
	    } //IF Inicio
	    return retorno;
}

int mostrarAvion(int idAvion, int idViaje, int idMarca,int matricula,int modelo, int cantAsientos,eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM)
{
    int retorno = -1;
    char descripcionM[20];
    char descripcionV[20];
    cargarDescripcionMarcaDesdeId(idMarca,aMarcas,tamM,descripcionM);
    cargarDescripcionViajeDesdeId(idViaje,aViajes, tamV, descripcionV);

    printf("%d       %-10s %-20s %-10d %-10d  %-7d\n", idAvion, descripcionV,descripcionM,matricula, modelo,cantAsientos);
    retorno = 1;

  return retorno;
}

int mostrarAviones(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM)
{
    int retorno = -1;
    if(aAviones != NULL &&tamA >0){
        printf("idAvion   Viaje     Marca            Matricula       Modelo   CantidadAsientos      \n");
    for (int i=0; i<tamA; i++)
    {
        if(aAviones[i].isEmpty == 0){

        mostrarAvion(aAviones[i].idAvion,
        aAviones[i].idViaje,
        aAviones[i].idMarca,
        aAviones[i].matricula,
        aAviones[i].modelo,
		aAviones[i].cantAsientos,
		aViajes,
		tamV,
		aMarcas,
		tamM);
        }
       retorno = 1;
    }
    }
    return retorno;
}
int bajaAvion(eAvion aAviones[],int tamA, eViaje aViajes[],int tamV,eMarca aMarcas[], int tamM){
    int retorno = -1;
    int idAvion;
    int posicion;
    char seguir = 's';
    if(aAviones != NULL && tamA > 0){
        do{
    mostrarAviones(aAviones,tamA,aViajes,tamV,aMarcas,tamM);
    printf("\n Ingrese el id del avion que quiere dar de baja: ");
    scanf("%d", &idAvion);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    while(posicion == -1){
    mostrarAviones(aAviones,tamA,aViajes,tamV,aMarcas,tamM);
    printf("\n Ingrese el id del avion que quiere dar de baja: ");
    scanf("%d", &idAvion);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    }
       aAviones[posicion].isEmpty = 1;
       retorno = 1;
    printf("Desea dar de baja otro avion? \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    }
    return retorno;
}

int modificarAvion(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM){
    int retorno = -1;
    int opcionSubMenu;
    int posicion;
    int idAvion;
    char seguir = 's';
    if(aAviones != NULL && tamA > 0){
        do{
    mostrarAviones(aAviones,tamA,aViajes, tamV, aMarcas, tamM);
    printf("\n Ingrese el id del avion que quiere modificar: ");
    scanf("%d", &idAvion);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    while( posicion == -1){
    mostrarAviones(aAviones,tamA,aViajes, tamV, aMarcas, tamM);
    printf("\n Ingrese el id del avion que quiere modificar: ");
    scanf("%d", &idAvion);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    }
    opcionSubMenu = menuModificaciones();
    if( opcionSubMenu == 1){
        printf("Ingrese el modelo: \n");
        scanf("%d", &aAviones[posicion].modelo);
        }
    else if(opcionSubMenu == 2){
   printf("Ingrese la cantidad de asientos que quiere modificar: \n");
   scanf("%d", &aAviones[posicion].cantAsientos);
    }
    printf("Quiere modificar otro avion?: \n");
    fflush(stdin);
    scanf("%c", &seguir);
    }while(seguir == 's');
    }
    return retorno;
}
int buscarAvion(eAvion aAviones[], int tamA, int* idAvion){
    int retorno = -1;
    if(aAviones!= NULL && idAvion != NULL && tamA >0){
         for(int i=0; i<tamA;i++){
        if(aAviones[i].idAvion == *idAvion && aAviones[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}
int ordenarAvionPorCantidadAsientos(eAvion aAviones[],int tamA)
{
    int retorno=-1;
    eAvion auxAvion;
    if(aAviones!=NULL && tamA)
    {
        retorno=0;
        for(int i=0; i<tamA-1 && !aAviones[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamA && !aAviones[j].isEmpty; j++)
            {
                 if(aAviones[i].cantAsientos > aAviones[j].cantAsientos)
                {
                    auxAvion = aAviones[i];
                    aAviones[i] = aAviones[j];
                    aAviones[j] = auxAvion;
                }
            }
        }
    }
    return retorno;
}
int ordenarAvionPorMarca(eAvion aAviones[],int tamA, eMarca aMarcas[], int tamM)
{
    int retorno=-1;
    eAvion auxAvion;
    char descripcion[20];
    char descripcion2[20];

    if(aAviones!=NULL && tamA && aMarcas != NULL && tamM >0)
    {
    	retorno=0;

        for(int i=0; i<tamA-1 && !aAviones[i].isEmpty; i++)
        {
        	cargarDescripcionMarcaDesdeId(aAviones[i].idMarca ,aMarcas,tamM,descripcion);
            for(int j=i+1; j<tamA && !aAviones[j].isEmpty; j++)
            {
            	cargarDescripcionMarcaDesdeId(aAviones[j].idMarca ,aMarcas,tamM,descripcion);
                 if(strcmp(descripcion,descripcion2)>0)
                {
                    auxAvion = aAviones[i];
                    aAviones[i] = aAviones[j];
                    aAviones[j] = auxAvion;
                }
                 strcpy(descripcion2, " ");
            }
            strcpy(descripcion, " ");
        }
    }
    return retorno;
}

