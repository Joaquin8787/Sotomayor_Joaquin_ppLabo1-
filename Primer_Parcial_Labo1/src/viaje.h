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

/// @brief muestra por pantalla 1 viaje
///
/// @param idViaje int id del viaje
/// @param kms float cantidad de kilometros del viaje
/// @param aViajes[] aViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @return int retorna 1 si pudo mostrar el viaje y -1 si no lo logro
int mostrarViaje(int idViaje,float kms, eViaje aViajes[],int tamV);

/// @brief muestra el listado de los viajes dados de alta
///
/// @param aViajes[] aViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @return int retorna 1 si pudo mostrar el array de viajes y -1 si no lo logro
int mostrarViajes(eViaje aViajes[],int tamV);

/// @brief recorre el array de viajes y se fija si esta vacio
///
/// @param aViajes[] aViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @return int retorna 1 si el array esta vacio y -1 si no lo esta
int arrayVacioViajes(eViaje aViajes[], int tamV);

/// @brief recibe el id de una marca y carga su descripcion en una variable
///
/// @param idViaje int id del viaje
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param descripcion[] char array de caracteres donde se guardara  la descripcion
/// @return int retorna 1 si pudo cargar la descripcion y -1 si no lo logro
int cargarDescripcionViajeDesdeId(int idViaje,eViaje aViajes[], int tamV, char descripcion[]);

/// @brief recibe la descripcion de un viaje y retorna su id
///
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param descripcion[] char array de caracteres donde esta la descripcion
/// @return int si pudo encontrar un viaje con la misma descripcion devuelve su id y devuelve -1 si no lo logro
int mostrarIdViajeDesdeDescripcion(eViaje aViajes[],int tamV, char descripcion[]);

/// @brief da de alta una nueva marca, pide los datos correspondientes y le asigna un id autoincremental
///
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param idViaje int* direccion de memoria del id a asignar
/// @return retonra 1 si pudo dar de alta la marca y -1 si no lo logro
int altaViaje(eViaje aViajes[],int tamV,int* idViaje);

/// @brief pide al usuario ingresar el id de la marca que quiere dar de baja y le asigna un 0 a su campo isEmpty
///
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @return retorna 1 si pudo dar de baja la marca y -1 si no lo logro
int bajaViajes(eViaje aViajes[],int tamV);

/// @brief recorre el array de viajes hasta encontrar algun campo isEmpty en 1 y devuelve su indice
///
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param posicion int* direccion de memoria donde se guarda el indice
/// @return int retorna 1 si pudo encontrar algun indice vacio y -1 si no lo logro
int buscarLibreViaje(eViaje aViajes[], int tamV, int* posicion);

/// @brief recibe el id de una marca, lo busca y devuelve su indice en el array de viajes
///
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param idViaje int* direccion de memoria del id del viaje a buscar
/// @return int retorna el indice si pudo encontrar la marca y -1 si no lo logro
int buscarViajeId(eViaje aViajes[], int tamV, int* idViaje);

