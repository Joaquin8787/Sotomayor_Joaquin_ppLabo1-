/*
 * viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */

#ifndef VIAJE_H_
#define VIAJE_H_



#endif /* VIAJE_H_ */
#define TEXT_SIZE 25

typedef struct{
     int idViaje;
     char descripcion[TEXT_SIZE];
     float kms;
     int isEmpty;
}eViaje;
int mostrarViaje(int idViaje,float kms, eViaje aViajes[],int tamV);
int mostrarViajes(eViaje aViajes[],int tamV);
int arrayVacioViajes(eViaje aViajes[], int tamV);

int cargarDescripcionViajeDesdeId(int idViaje,eViaje aViajes[], int tamV, char descripcion[]);
int mostrarIdViajeDesdeDescripcion(eViaje aViajes[],int tamV, char descripcion[]);

int altaViaje(eViaje aViajes[],int tamV,int* idViaje);
int bajaViajes(eViaje aViajes[],int tamV);

int buscarLibreViaje(eViaje aViajes[], int tamV, int* posicion);
int buscarViajeId(eViaje aViajes[], int tamV, int* idViaje);

