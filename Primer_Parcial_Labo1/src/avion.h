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
     int dia;
     int mes;
     int anio;
}eFecha;

typedef struct{
     int idAvion;
     eFecha fecha;
     int matricula;
     int idViaje;
     int idMarca;
     int modelo;
     int cantAsientos;
     int isEmpty;
}eAvion;

/// @brief inicializa el array de aviones, asigna un 0 en cada campo y un 1 en el campo isEmpty
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño del array de aviones
/// @return int retorna 1 si pudo inicializar el array y -1 si no lo logro
int inicializarArrayAviones(eAvion aAviones[], int tamA);

/// @brief da de alta un nuevo avion, pide los datos correspondientes y le asigna un id autoincremental
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño del array de aviones
/// @param idAvion int* direccion de memoria del id a asignar
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño de array de viajes
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño de array de marcas
/// @return int retorna 1 si pudo dar de alta el avion y -1 si no lo logro
int altaAviones(eAvion aAviones[],int tamA,int* idAvion,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);

/// @brief pide al usuario ingresar el id del avion que quiere dar de baja y le asigna un 0 a su campo isEmpty
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño de array de aviones
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño de array de viajes
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño de array de marcas
/// @return int retorna 1 si pudo dar de baja al avion y -1 si no lo logro
int bajaAvion(eAvion aAviones[],int tamA, eViaje aViajes[],int tamV,eMarca aMarcas[], int tamM);

/// @brief modifica un avion seleccionado por el usuario
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño de array de aviones
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño de array de viajes
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño de array de marcas
/// @return int retorna 1 si pudo modificar al avion y -1 si no lo logro
int modificarAvion(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);

/// @brief muestra el listado de los aviones dado de alta
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño del array de aviones
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño de array de viajes
/// @param aMarcas[] eMarca array del marcas
/// @param tamM int tamaño del array de marcas
/// @return int retorna 1 si pudo mostrar el array de aviones y -1 si no lo logro
int mostrarAviones(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);

/// @brief muestra por pantalla 1 avion
///
/// @param idAvion int id del avion
/// @param fecha eFecha del viaje que realiza
/// @param idViaje int id del viaje que realiza
/// @param idMarca int id de la marca del avion
/// @param matricula int matricula del avion
/// @param modelo int modelo del avion
/// @param cantAsientos int cantidad de asientos que tiene el avion
/// @param aViajes[] eViaje array de viajes
/// @param tamV int tamaño del array de viajes
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @return int retorna 1 si pudo mostrar  el avion y -1 si no lo logro
int mostrarAvion(int idAvion,eFecha fecha, int idViaje, int idMarca,int matricula,int modelo, int cantAsientos,eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM);

/// @brief recibe el id de un avion, lo busca y devuelve su indice en el array de aviones
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño de array de aviones
/// @param idAvion int* direccion de memoria del id del avion a buscar
/// @return int retorna 1 si pudo encontrar el avion y -1 si no lo logro
int buscarAvion(eAvion aAviones[], int tamA, int* idAvion);

/// @brief recorre el array de aviones hasta encontrar algun campo isEmpty en 1 y devuelve su indice
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño de array de aviones
/// @param posicion int* direccion de memoria donde se guarda el indice
/// @return int retorna 1 si pudo encontrar algun indice vacio y -1 si no lo logro
int buscarLibreAvion(eAvion aAviones[], int tamA, int* posicion);

/// @brief recorre el array de aviones y se fija si esta vacio
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño del array de aviones
/// @return int retorna 1 si el array esta vacio y -1 si no lo esta
int arrayVacioAvion(eAvion aAviones[], int tamA);

/// @brief ordena el array de aviones de manera ascendente por matricula y si hay alguna matricula repetida, ordena por marca
///
/// @param aAviones[] eAvion array de aviones
/// @param tamA int tamaño del array de aviones
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @return int retorna 1 si pudo ordenar el array de aviones y -1 si no lo logro
int ordenarAvionPorMarca(eAvion aAviones[],int tamA, eMarca aMarcas[], int tamM);
