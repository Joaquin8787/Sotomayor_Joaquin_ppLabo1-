/*
 * avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */

#ifndef AVION_H_
#define AVION_H_



#endif /* AVION_H_ */
#include "marca.h"
#include "viaje.h"

typedef struct{
     int idAvion;
     int matricula;
     int idViaje;
     int idMarca;
     int modelo;
     int cantAsientos;
     int isEmpty;
}eAvion;

int inicializarArrayAviones(eAvion aAviones[], int tamA);

int altaAviones(eAvion aAviones[],int tamA,int* idAvion,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);
int bajaAvion(eAvion aAviones[],int tamA, eViaje aViajes[],int tamV,eMarca aMarcas[], int tamM);
int modificarAvion(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);

int mostrarAviones(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);
int mostrarAvion(int idAvion, int idViaje, int idMarca,int matricula,int modelo, int cantAsientos,eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM);

int buscarAvion(eAvion aAviones[], int tamA, int* idAvion);
int buscarLibreAvion(eAvion aAviones[], int tamA, int* posicion);

int arrayVacioAvion(eAvion aAviones[], int tamA);

int ordenarAvionPorCantidadAsientos(eAvion aAviones[],int tamA);
int ordenarAvionPorMarca(eAvion aAviones[],int tamA, eMarca aMarcas[], int tamM);
