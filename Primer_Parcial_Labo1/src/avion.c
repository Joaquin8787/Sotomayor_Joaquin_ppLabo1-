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
        aAviones[i].fecha.dia = 0;
        aAviones[i].fecha.mes = 0;
        aAviones[i].fecha.anio = 0;
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

int buscarAvion(eAvion aAviones[], int tamA, int* idAvion){
    int retorno = -1;
    if(aAviones!= NULL && idAvion != NULL && tamA >0){
        for(int i=0; i<tamA;i++){
        if(aAviones[i].idAvion == *idAvion && aAviones[i].isEmpty == 0){
            retorno = i; //SI EL ID QUE INGRESE EXISTE EN EL ARRAY DE AVIONES DEVUELVO EL INDICE
            break;
        }
    }
    }
    return retorno;
}

int altaAviones(eAvion aAviones[],int tamA,int* idAvion,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM){
	    int retorno = -1;
	    int posicion;
	    eFecha auxFecha;
	    int idAuxV;
	    int idAuxM;
	    int auxModelo;
	    int auxMatricula;
	    int auxCantAsientos;
	    char auxViaje[TEXT_SIZE];
	    char auxMarca[TEXT_SIZED];
	    char seguir = 's';

	     if(aAviones != NULL && idAvion != NULL && aViajes != NULL && aMarcas != NULL &&tamA > 0 && tamV > 0 && tamM > 0){
	         do{
	        if(buscarLibreAvion(aAviones,tamA, &posicion) == 1){

	        if(joaquin_getNumero(&auxFecha.dia,"Ingrese el dia: ", "ERROR!!!\n",1,31,2) ==1
	        && joaquin_getNumero(&auxFecha.mes,"Ingrese el mes: ", "ERROR!!!\n",1,12,2) ==1
	        && joaquin_getNumero(&auxFecha.anio,"Ingrese el anio: ", "ERROR!!!\n",2021,2030,2)==1){
	        	aAviones[posicion].fecha = auxFecha;
	        }
	    	mostrarViajes(aViajes,tamV);
	    	joaquin_getNombre(auxViaje, "Ingrese el nombre del viaje que realiza: \n", "ERROR, tipo de dato no valido\n", TEXT_SIZE, 2);
	        idAuxV = mostrarIdViajeDesdeDescripcion(aViajes,tamV, auxViaje);
	        while(idAuxV == -1){
	        printf("El nombre del viaje que ingreso no existe \n");
	        mostrarViajes(aViajes,tamV);
	        joaquin_getNombre(auxViaje, "Ingrese el nombre del viaje que realiza: \n", "ERROR, tipo de dato no valido\n", TEXT_SIZE, 2);
	        idAuxV = mostrarIdViajeDesdeDescripcion(aViajes,tamV, auxViaje);
	        }
	        aAviones[posicion].idViaje = idAuxV;

	        mostrarMarcas(aMarcas,tamM);
	        joaquin_getNombre(auxMarca, "Ingrese el nombre de la marca del avion: \n","ERROR, tipo de dato no valido\n", TEXT_SIZED, 2);
	        idAuxM = mostrarIdMarcaDesdeDescripcion(aMarcas,tamM, auxMarca);
	        while(idAuxM == -1){
	        printf("El nombre de la marca que ingreso no existe \n");
	        mostrarMarcas(aMarcas,tamM);
	        joaquin_getNombre(auxMarca, "Ingrese el nombre de la marca del avion: \n","ERROR, tipo de dato no valido\n", TEXT_SIZED, 2);
	        idAuxM = mostrarIdMarcaDesdeDescripcion(aMarcas,tamM, auxMarca);
	       }
	        aAviones[posicion].idMarca = idAuxM;

	        if(joaquin_getNumero(&auxModelo,"Ingrese el modelo del avion(1995/2021): \n", "ERROR!!!\n",1995,2021,2)==1
	        &&joaquin_getNumero(&auxMatricula,"Ingrese la matricula del avion(1000/5000):  \n", "ERROR!!!\n",1000,5000,2)==1
	        &&joaquin_getNumero(&auxCantAsientos,"Ingrese la cantidad de asientos que tiene el avion(30/80):  \n", "ERROR!!!\n",30,80,2)==1){
	        	aAviones[posicion].modelo = auxModelo;
	            aAviones[posicion].matricula = auxMatricula;
	        	aAviones[posicion].cantAsientos = auxCantAsientos;
	        	aAviones[posicion].isEmpty = 0;
	        	aAviones[posicion].idAvion = *idAvion;
	        	(*idAvion)++;
	        	retorno = 1;
	        }

	    }
	    else{
	        printf("No hay posiciones disponible para ingresar otro avion \n ");
	    }
	    joaquin_getCaracter(&seguir, "Desea dar de alta otro avion? \n (s/n): ", "ERROR!!!\n",'s','n', 2);
	    }while(seguir == 's');
	    }
	    return retorno;
}

int mostrarAvion(int idAvion,eFecha fecha, int idViaje, int idMarca,int matricula,int modelo, int cantAsientos,eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM)
{
    int retorno = -1;
    char descripcionM[TEXT_SIZED];
    char descripcionV[TEXT_SIZE];
    if(aViajes != NULL && aMarcas != NULL && tamV > 0 && tamM > 0){
    	cargarDescripcionMarcaDesdeId(idMarca,aMarcas,tamM,descripcionM);
    	cargarDescripcionViajeDesdeId(idViaje,aViajes, tamV, descripcionV);

    	printf("%d       %-10s    %-17s %-10d      %-10d  %-7d          %.2d/%.2d/%.2d \n", idAvion, descripcionV,descripcionM,matricula, modelo,cantAsientos,fecha.dia,fecha.mes,fecha.anio);
    	retorno = 1;
    }
  return retorno;
}

int mostrarAviones(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM)
{
    int retorno = -1;
    if(aAviones != NULL && aViajes != NULL && aMarcas != NULL && tamA >0 && tamV > 0 && tamM >0){
    	printf("-------------------------------------------------------------------------------------------------\n");
    	printf("-------------------------------------------------------------------------------------------------\n");
        printf("idAvion   VIAJE         MARCA            MATRICULA       MODELO   CANTIDAD ASIENTOS      FECHA    \n");
    for (int i=0; i<tamA; i++)
    {
        if(aAviones[i].isEmpty == 0){

        mostrarAvion(
        aAviones[i].idAvion,
		aAviones[i].fecha,
        aAviones[i].idViaje,
        aAviones[i].idMarca,
        aAviones[i].matricula,
        aAviones[i].modelo,
		aAviones[i].cantAsientos,
		aViajes,
		tamV,
		aMarcas,
		tamM);
        retorno = 1;
        }

    }
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    }
    return retorno;
}
int bajaAvion(eAvion aAviones[],int tamA, eViaje aViajes[],int tamV,eMarca aMarcas[], int tamM){
    int retorno = -1;
    int idAvion;
    int posicion;
    char confirmar;
    char seguir = 's';
    if(aAviones != NULL && aViajes != NULL && aMarcas != NULL && tamA > 0 && tamV > 0 && tamM > 0){
    do{
    mostrarAviones(aAviones,tamA,aViajes,tamV,aMarcas,tamM);
    joaquin_getNumero(&idAvion,"Ingrese el id del avion que quiere dar de baja: \n", "ERROR!!!\n",500,1000,2);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    //Valido que el id que ingrese el usuario es alguno de los que estan dados de alta
    while(posicion == -1){
    printf("ERROR... El id ingresado no existe \n");
    mostrarAviones(aAviones,tamA,aViajes,tamV,aMarcas,tamM);
    joaquin_getNumero(&idAvion,"Ingrese el id del avion que quiere dar de baja: \n", "ERROR!!!\n",500,1000,2);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    }
    joaquin_getCaracter(&confirmar, "Esta seguro que quiere eliminar este avion?\n (s/n): ", "ERROR!!!\n",'s','n', 2);
    if(confirmar == 's'){
    	aAviones[posicion].isEmpty = 1;
    	printf("Baja exitosa!!!\n");
    	retorno = 1;
    }
    joaquin_getCaracter(&seguir, "Desea dar de baja otro avion? \n (s/n): ", "ERROR!!!\n",'s','n', 2);
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
    if(aAviones != NULL && aViajes != NULL && aMarcas != NULL && tamA > 0 && tamV > 0 && tamM > 0){
    do{
    mostrarAviones(aAviones,tamA,aViajes, tamV, aMarcas, tamM);
    joaquin_getNumero(&idAvion,"Ingrese el id del avion que quiere modificar: \n", "ERROR!!!\n",500,1000,2);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    while( posicion == -1){
    printf("ERROR. El id ingresado no existe \n ");
    mostrarAviones(aAviones,tamA,aViajes, tamV, aMarcas, tamM);
    joaquin_getNumero(&idAvion,"Ingrese el id del avion que quiere modificar: \n ", "ERROR!!!\n",500,1000,2);
    posicion = buscarAvion(aAviones,tamA, &idAvion);
    }
    opcionSubMenu = menuModificaciones();
    if( opcionSubMenu == 1){
    printf(" ---- MODIFICACION DEL MODELO --- \n");
	if(joaquin_getNumero(&aAviones[posicion].modelo,"Ingrese la matricula del avion(1000/5000):\n", "ERROR!!!\n",1000,5000,2) == 1){
		printf("Modificacion exitosa!!! \n");
	}
	else{
		printf("Hubo un error al modificar el modelo del avion \n");
	}
    }
    else if(opcionSubMenu == 2){
    	printf(" ---- MODIFICACION CANTIDAD DE ASIENTOS DEL AVION --- \n");
    	if(joaquin_getNumero(&aAviones[posicion].cantAsientos,"Ingrese la cantidad de asientos que tiene el avion(30/80): \n", "ERROR!!!\n",30,80,2) == 1){
    		printf("Modificacion exitosa!!! \n");
    	}
    	else{
    		printf("Hubo un error al modificar la cantidad de asientos del avion \n");
    	}
    }
    retorno = 1;
    joaquin_getCaracter(&seguir, "Desea dar modificar otro avion? \n (s/n): ", "ERROR!!!\n",'s','n', 2);
    }while(seguir == 's');
    }
    return retorno;
}

int ordenarAvionPorMarca(eAvion aAviones[],int tamA, eMarca aMarcas[], int tamM)
{
    int retorno=-1;
    eAvion auxAvion;
    char descripcion[TEXT_SIZED];
    char descripcion2[TEXT_SIZED];

    if(aAviones!=NULL && tamA && aMarcas != NULL && tamM >0)
    {
    	retorno=0;
    	//BURBUJEO
        for(int i=0; i<tamA-1 && !aAviones[i].isEmpty; i++) //RECORRO HASTA QUE
        {
        	cargarDescripcionMarcaDesdeId(aAviones[i].idMarca ,aMarcas,tamM,descripcion); //CARGO LA PRIMERA DESCRIPCION DE LA MARCA
            for(int j=i+1; j<tamA && !aAviones[j].isEmpty; j++)
            {
            	cargarDescripcionMarcaDesdeId(aAviones[j].idMarca ,aMarcas,tamM,descripcion2);//CARGO LA SEGUNDA DESCRIPCION DE LA MARCA
                 if(aAviones[i].matricula > aAviones[j].matricula ||( aAviones[i].matricula == aAviones[j].matricula && strcmp(descripcion,descripcion2)>0))
                {
                    auxAvion = aAviones[i];
                    aAviones[i] = aAviones[j];
                    aAviones[j] = auxAvion;
                }
                 strcpy(descripcion2, " ");
            }
            strcpy(descripcion, " ");
        }
     retorno = 1;
    }
    return retorno;
}
