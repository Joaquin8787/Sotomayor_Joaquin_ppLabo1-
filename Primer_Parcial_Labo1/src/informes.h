/*
 * informes.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
#include "avion.h"

int promedioAvionesPorFecha(eAvion aAviones[], int tamA, eViaje aViajes[],int tamV);
int informarAvionporMarca(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM);
int mostrarAvionesBoing(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM);
int mostrarMatriculaYMarcaNeuquen(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM);
int mostrarKmsRecorridosPorATR(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM);
int informarCantidadAsientosporModelo(eAvion aAviones[],int tamA);
