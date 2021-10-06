/*
 * joaquin.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Usuario
 */

#ifndef JOAQUIN_H_
#define JOAQUIN_H_



#endif /* JOAQUIN_H_ */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int menuOpciones();

int menuModificaciones();

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el numero o -1 si no
 *
 */
int joaquin_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int joaquin_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int joaquin_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos);

int joaquin_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);

int joaquin_getTextoEspecial(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);