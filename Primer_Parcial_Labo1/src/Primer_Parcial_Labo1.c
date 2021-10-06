/*
 ============================================================================
 Name        : Primer_Parcial_Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "joaquin.h"
#include "avion.h"


#define TAM_MAR 4
#define TAM_VIA 5
#define TAM_AVION 3


int main(void) {
	setbuf(stdout, NULL);
/*
 *
{1003, Bombardier}
 */
	eMarca arrayMarcas[TAM_MAR] = {{1002,"Boeing",0},{101,"Airbus",0},{1003,"ATR",0},{1004,"Bombardier",0}};
	eViaje arrayViajes[TAM_VIA] = {
			{100, "Salta", 1462,0},
			{101, "Tucuman", 1247,0},
			{102, "Neuquen", 1139,0},
			{103, "Corrientes", 670},
			{104, "Chubut", 1735,0}};

    eAvion arrayAviones[TAM_AVION];

    //int idMarca = 1000;
    //int idViaje = 100;
    int idAvion = 500;

	char salir = 'n';
	inicializarArrayAviones(arrayAviones,TAM_AVION);
	do{
		switch(menuOpciones()){
		case 1:
			if(altaAviones(arrayAviones,TAM_AVION,&idAvion,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR)){
				printf("Alta exitosa!!! \n");
			}
			else{
				printf("Hubo un problema al dar de alta el avion \n");
			}

	    break;
		case 2:
			if(arrayVacioAvion(arrayAviones,TAM_AVION) == -1){
				modificarAvion(arrayAviones,TAM_AVION,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR);
			}
			else{
				printf("Primero debe dar de alta algun avion \n");
			}

		break;
		case 3:
			if(arrayVacioAvion(arrayAviones,TAM_AVION) == -1){
				bajaAvion(arrayAviones,TAM_AVION,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR);
			}
			else{
				printf("Primero debe dar de alta algun avion \n");
			}

		break;
		case 4:
			if(arrayVacioAvion(arrayAviones,TAM_AVION) == -1){
			mostrarAviones(arrayAviones,TAM_AVION,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR);
			printf("Ordenando...");
			ordenarAvionPorCantidadAsientos(arrayAviones,TAM_AVION);
			mostrarAviones(arrayAviones,TAM_AVION,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR);
			}
			else{
			printf("Primero debe dar de alta algun avion \n");
			}

	    break;
		case 5:

			if(arrayVacioViajes(arrayViajes,TAM_VIA)==-1){
			mostrarViajes(arrayViajes,TAM_VIA);
			}
			else{
			printf("Primero debe dar de alta algun viaje \n");
			}
			system("pause");
		break;
		case 6:
			if(arrayVacioMarcas(arrayMarcas,TAM_MAR)==-1){
				mostrarMarcas(arrayMarcas,TAM_MAR);
		     }
			else{
			printf("Primero debe dar de alta algun viaje \n");
			}
			system("pause");
		break;
		case 7:
			printf("Esta seguro de que quiere salir? \n");
		    fflush(stdin);
		    scanf("%c",&salir);
	   break;


		}

	}while(salir == 'n' );
	 printf("... Ha salido del menu ");

	return EXIT_SUCCESS;
}
