/*
 * marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */

#ifndef MARCA_H_
#define MARCA_H_



#endif /* MARCA_H_ */
#define TEXT_SIZED 20
typedef struct{
     int id;
     char descripcion[TEXT_SIZED];
     int isEmpty;
}eMarca;

/// @brief recorre el array de marcas y se fija si esta vacio
///
/// @param aMarcas[] eMarca array de aviones
/// @param tamM int tamaño del array de marcas
/// @return int retorna 1 si el array esta vacio y -1 si no lo esta

int arrayVacioMarcas(eMarca aMarcas[], int tamM);

/// @brief muestra por pantalla 1 marca
///
/// @param idMarca int id de la marca
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @return int retorna 1 si pudo mostrar la marca y -1 si no lo logro
int mostrarMarca(int idMarca,eMarca aMarcas[],int tamM);

/// @brief muestra el listado de las marcas dadas de alta
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @return retonra 1 si pudo mostrar el array de marcas y -1 si no lo logro
int mostrarMarcas(eMarca aMarcas[],int tamM);

/// @brief recibe el id de una marca y carga su descripcion en una variable
///
/// @param idMarca int id de la marca
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @param descripcion[] char array de caracteres donde se guardara  la descripcion
/// @return int retorna 1 si pudo cargar la descripcion y -1 si no lo logro
int cargarDescripcionMarcaDesdeId(int idMarca,eMarca aMarcas[], int tamM, char descripcion[]);

/// @brief recibe la descripcion de una marca y retorna su id
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @param descripcion[] char array de caracteres donde esta la descripcion
/// @return int si pudo encontrar una marca con la misma descripcion devuelve su id y devuelve -1 si no lo logro
int mostrarIdMarcaDesdeDescripcion(eMarca aMarcas[],int tamM, char descripcion[]);

/// @brief recorre el array de marcas hasta encontrar algun campo isEmpty en 1 y devuelve su indice
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @param posicion int* direccion de memoria donde se guarda el indice
/// @return int retorna 1 si pudo encontrar algun indice vacio y -1 si no lo logro
int buscarLibreMarca(eMarca aMarcas[], int tamM, int* posicion);

/// @brief recibe el id de una marca, lo busca y devuelve su indice en el array de marcas
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @param idMarcas int* direccion de memoria del id de la marca a buscar
/// @return int retorna el indice si pudo encontrar la marca y -1 si no lo logro
int buscarMarcaId(eMarca aMarcas[], int tamM, int* idMarcas);

/// @brief pide al usuario ingresar el id de la marca que quiere dar de baja y le asigna un 0 a su campo isEmpty
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @return retorna 1 si pudo dar de baja la marca y -1 si no lo logro
int bajaMarcas(eMarca aMarcas[],int tamM);

/// @brief da de alta una nueva marca, pide los datos correspondientes y le asigna un id autoincremental
///
/// @param aMarcas[] eMarca array de marcas
/// @param tamM int tamaño del array de marcas
/// @param idMarcas int* direccion de memoria del id a asignar
/// @return retonra 1 si pudo dar de alta la marca y -1 si no lo logro
int altaMarca(eMarca aMarcas[],int tamM,int* idMarcas);

