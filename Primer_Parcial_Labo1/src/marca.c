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
#include "joaquin.h"

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
    char auxDescripcion[20];

     if(aMarcas != NULL && idMarcas != NULL &&tamM > 0){
    do{
    if(buscarLibreMarca(aMarcas,tamM, &posicion) == 1){
    	if(joaquin_getNombre(auxDescripcion, "Ingrese el nombre de la marca: \n", "ERROR, tipo de dato no valido\n", 20, 2) == 0){
    		strcpy(aMarcas[posicion].descripcion, auxDescripcion);
    		aMarcas[posicion].isEmpty = 0;
    	    aMarcas[posicion].id = *idMarcas;
    		(*idMarcas)++;
    		retorno = 1;
    	}
    }
    else{
        printf("No hay posiciones disponible para ingresar otra marca");
    }
    joaquin_getCaracter(&seguir, "Desea dar de alta otra marca? \n (s/n): ", "ERROR \n",'s','n', 2);
    }while(seguir == 's');
    }
    return retorno;
}
int bajaMarcas(eMarca aMarcas[],int tamM){
    int retorno = -1;
    int idMarcas;
    int posicion;
    char confirmar;
    char seguir = 's';
    if(aMarcas != NULL && tamM > 0){
    do{
    mostrarMarcas(aMarcas,tamM);
    joaquin_getNumero(&idMarcas,"Ingrese el id de la marca que quiere dar de baja: ", "ERROR. el id del avion debe ser a partir del 1000",500,1000,2);
    posicion = buscarMarcaId(aMarcas,tamM,&idMarcas);
    //valido que el id de la marca que ingreso el usuario este dado de alta
    while(posicion == -1){
    	mostrarMarcas(aMarcas,tamM);
    	joaquin_getNumero(&idMarcas,"Ingrese el id de la marca que quiere dar de baja: ", "ERROR. el id del avion debe ser a partir del 1000",500,1000,2);
    	posicion = buscarMarcaId(aMarcas,tamM,&idMarcas);
    }
    joaquin_getCaracter(&confirmar, "Esta seguro que quiere eliminar esta marca?\n (s/n): ", "ERROR \n",'s','n', 2);
    if(confirmar == 's'){
    	aMarcas[posicion].isEmpty = 1;
    	retorno = 1;
    }

    joaquin_getCaracter(&seguir, "Desea dar de baja otra marca? \n (s/n): ", "ERROR \n",'s','n', 2);
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
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("idMarca    descripcion \n");
    for (int i=0; i<tamM; i++)
    {
        if(aMarcas[i].isEmpty == 0){
        mostrarMarca(aMarcas[i].id, aMarcas,tamM);
        retorno = 1;
        }
    }
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");

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
