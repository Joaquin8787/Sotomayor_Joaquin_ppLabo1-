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

	int opcionMenu;
	eMarca arrayMarcas[TAM_MAR] = {
			{1001,"Boeing",0},
			{1002,"Airbus",0},
			{1003,"ATR",0},
			{1004,"Bombardier",0}
	};
	eViaje arrayViajes[TAM_VIA] = {
			{100, "Salta", 1462.5,0},
			{101, "Tucuman", 1247.6,0},
			{102, "Neuquen", 1139.4,0},
			{103, "Corrientes", 670},
			{104, "Chubut", 1735.8,0}};

    eAvion arrayAviones[TAM_AVION] = {
    		{500,{6,9,2021},2500,100,1002,1998,20,0},
			{501,{23,11,2021},2500,103,1002,2004,60,0},
			{502,{4,1,2022},4000,104,1004,1999,50,0}
    };

    //int idMarca = 1000;
    //int idViaje = 100;
      int idAvion = 500;

	char salir = 'n';
	//inicializarArrayAviones(arrayAviones,TAM_AVION);
	do{
		menuOpciones(&opcionMenu);
		switch(opcionMenu){
		case 1:
			if(altaAviones(arrayAviones,TAM_AVION,&idAvion,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR) == 1){
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
			printf("ORDENANDO... \n");
			getchar();
			ordenarAvionPorMarca(arrayAviones,TAM_AVION,arrayMarcas,TAM_MAR);
			mostrarAviones(arrayAviones,TAM_AVION,arrayViajes,TAM_VIA,arrayMarcas,TAM_MAR);
			}
			else{
			printf("Primero debe dar de alta algun avion \n");
			}
			getchar();
	    break;
		case 5:
			if(arrayVacioViajes(arrayViajes,TAM_VIA)==-1){
			mostrarViajes(arrayViajes,TAM_VIA);
			}
			else{
			printf("Primero debe dar de alta algun viaje \n");
			}
			getchar();
		break;
		case 6:
			if(arrayVacioMarcas(arrayMarcas,TAM_MAR)==-1){
				mostrarMarcas(arrayMarcas,TAM_MAR);
		     }
			else{
			printf("Primero debe dar de alta algun viaje \n");
			}
			getchar();
		break;
		case 7:
			joaquin_getCaracter(&salir, "Esta seguro que quiere salir? \n (s/n): ", "ERROR!!!\n",'s','n', 2);
	   break;
		}

	}while(salir == 'n' );
	 printf("... Ha salido del menu ");

	return EXIT_SUCCESS;
}
