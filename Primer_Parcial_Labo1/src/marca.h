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

int arrayVacioMarcas(eMarca aMarcas[], int tamM);

int mostrarMarca(int idMarca,eMarca aMarcas[],int tamM);
int mostrarMarcas(eMarca aMarcas[],int tamM);

int cargarDescripcionMarcaDesdeId(int idMarca,eMarca aMarcas[], int tamM, char descripcion[]);
int mostrarIdMarcaDesdeDescripcion(eMarca aMarcas[],int tamM, char descripcion[]);

int buscarLibreMarca(eMarca aMarcas[], int tamM, int* posicion);
int buscarMarcaId(eMarca aMarcas[], int tamM, int* idMarcas);

int bajaMarcas(eMarca aMarcas[],int tamM);
int altaMarca(eMarca aMarcas[],int tamM,int* idMarcas);

