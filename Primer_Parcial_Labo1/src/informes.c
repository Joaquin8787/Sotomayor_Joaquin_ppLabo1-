/*
 * informes.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "joaquin.h"
#include "informes.h"

int informarAvionporMarca(eAvion aAviones[],int tamA,eViaje aViajes[],int tamV,eMarca aMarcas[],int tamM){
			int retorno = -1;
			int idMarca;
			int posicion;
			if(aAviones != NULL && aViajes != NULL && aMarcas != NULL && tamA > 0 && tamV > 0 && tamM > 0)
			{
				     printf("---------- MOSTRAR AVIONES DE LA MISMA MARCA ---------- \n");
				     mostrarMarcas(aMarcas,tamM);
				     joaquin_getNumero(&idMarca,"Ingrese el id de la marca: ", "ERROR. el id de la marca debe ser a partir del 1000 \n",1000,2000,2);
				     posicion = buscarMarcaId(aMarcas,tamM, &idMarca);
				     while(posicion == -1){
				     printf("ERROR... El id ingresado es invalido \n");
				     mostrarMarcas(aMarcas,tamM);
				     joaquin_getNumero(&idMarca,"Ingrese el id de la marca: ", "ERROR. el id de la marca debe ser a partir del 1000 \n",1000,2000,2);
				     posicion = buscarMarcaId(aMarcas,tamM, &idMarca);
				     }
				  if(posicion != -1){
					  printf("Los aviones con esa marca son: \n");
					  for(int i=0;i<tamA;i++){
					  if(idMarca == aAviones[i].idMarca){
						  mostrarAvion(
						  				        aAviones[i].idAvion,
						  						aAviones[i].fecha,
						  				        aAviones[i].idViaje,
						  				        aAviones[i].idMarca,
						  				        aAviones[i].matricula,
						  				        aAviones[i].modelo,
						  						aAviones[i].cantAsientos,
						  						aViajes,
						  						tamV,
						  						aMarcas,
						  						tamM);
						  				retorno = 1;
					  }
				     }
					 if(retorno == -1){
					 printf("No se encontraron aviones con esa marca \n");
					  }

				   }

			}

			return retorno;
		}
int informarCantidadAsientosporModelo(eAvion aAviones[],int tamA){
			int retorno = -1;
			int auxModelo;
			int acumuladorCantidadAsientos = 0;

			if(aAviones != NULL && tamA > 0){
			 printf("---------- MOSTRAR CANTIDAD ASIENTOS POR MODELO---------- \n");
			if(joaquin_getNumero(&auxModelo,"Ingrese el modelo del avion(1995/2021): \n", "ERROR!!!\n",1995,2021,2)==1){
				for(int i = 0; i<tamA; i++){
					if(aAviones[i].modelo == auxModelo){
						acumuladorCantidadAsientos += aAviones[i].cantAsientos;
						retorno = 1;
					}
				}
			}
			if(retorno == 1){
				printf("La cantidad de asientos para el modelo %d es de %d asientos \n",auxModelo,acumuladorCantidadAsientos);
			}
			else{
				printf("No hay ningun avion con ese modelo dado de alta \n");
			}
				   }
			return retorno;
		}


int promedioAvionesPorFecha(eAvion aAviones[], int tamA, eViaje aViajes[],int tamV){
	int retorno = -1;
	eFecha auxFecha;
	int contador = 0;
	int posicion;
	float acumulador = 0;
	float promedio;
	printf("------ PROMEDIO DE AVIONES POR FECHA ----- \n");
	if(aAviones != NULL && tamA >0 && aViajes != NULL && tamV >0){
		if(joaquin_getNumero(&auxFecha.dia,"Ingrese el dia: ", "ERROR!!!\n",1,31,2) ==1
		&& joaquin_getNumero(&auxFecha.mes,"Ingrese el mes: ", "ERROR!!!\n",1,12,2) ==1
		&& joaquin_getNumero(&auxFecha.anio,"Ingrese el anio: ", "ERROR!!!\n",2021,2030,2)==1){
		for(int i = 0; i<tamA; i++){
			if(auxFecha.dia == aAviones[i].fecha.dia && auxFecha.mes == aAviones[i].fecha.mes && auxFecha.anio == aAviones[i].fecha.anio ){
				contador++;
				posicion = buscarViajeId(aViajes,tamV,&aAviones[i].idViaje);
				acumulador += aViajes[posicion].kms;
			}

		}
	 }
	promedio = (float) acumulador/contador;
	printf("El promedio de kms la fecha %d/%d/%d es de %.2f \n", auxFecha.dia,auxFecha.mes,auxFecha.anio,promedio);
  }
	return retorno;
}
int mostrarAvionesBoing(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM){
	int retorno = -1;
	printf("------ PROMEDIO DE AVIONES POR FECHA ----- \n");
	if(aAviones != NULL && aViajes != NULL && aMarcas != NULL &&tamA > 0 && tamV > 0 && tamM > 0){
		for(int i=0; i<tamA;i++){
			if(aAviones[i].idMarca == 1001){
				mostrarAvion(
				        aAviones[i].idAvion,
						aAviones[i].fecha,
				        aAviones[i].idViaje,
				        aAviones[i].idMarca,
				        aAviones[i].matricula,
				        aAviones[i].modelo,
						aAviones[i].cantAsientos,
						aViajes,
						tamV,
						aMarcas,
						tamM);
				retorno = 1;
			}
			}
	if(retorno == -1){
			printf("No hay ningun avion con la marca Boeing para mostrar \n");
		}
	}

	return retorno;
}

int mostrarMatriculaYMarcaNeuquen(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM){
	int retorno = -1;
	char descripcion[TEXT_SIZED];
	if(aAviones != NULL && tamA >0 && aViajes != NULL && tamV >0 && aMarcas != NULL && tamM >0){
		printf("------ AVIONES QUE VIAJAN A NEUQUEN ----- \n");
		printf("ID       MARTRICULA       MARCA  \n");
		for(int i=0; i<tamA;i++){
			if(aAviones[i].idViaje == 102){
				cargarDescripcionMarcaDesdeId(aAviones[i].idMarca,aMarcas,tamM,descripcion);
				printf("%d       %-10d        %s \n",aAviones[i].idAvion, aAviones[i].matricula, descripcion);
			}
				retorno = 1;
			}
			}
	return retorno;
	}

int mostrarKmsRecorridosPorATR(eAvion aAviones[], int tamA, eViaje aViajes[], int tamV, eMarca aMarcas[], int tamM){
	int retorno = -1;
	int posicion;
	float acumulador = 0;
	if(aAviones != NULL && tamA >0 && aViajes != NULL && tamV >0 && aMarcas != NULL && tamM >0){
	 for(int i=0; i<tamA;i++){
			if(aAviones[i].idMarca == 1003){ //si el avion es marca ATR
				posicion = buscarViajeId(aViajes,tamV,&aAviones[i].idViaje);
				acumulador +=  aViajes[posicion].kms;
				retorno = 1;
			}
		}
	 if(retorno == 1){
		 printf("Los kms totales recorridos por los aviones de marca ATR es de %.2f kms \n",acumulador);
	 }
	 else{
		 printf("No hay ningun avion de la marca ATR dado de alta \n");
	 }

	}
	return retorno;
}
int mostrarAvionesMas1000Kms(eViaje aAviones[], int tamA){
	int retorno = -1;
	if(aAviones != NULL && tamA >0){
		for(int i=0; i<tamA;i++){
			if(aAviones[i].kms > 1300){
				mostrarViaje(aAviones[i].idViaje,aAviones[i].kms,aAviones,tamA);
				retorno = 1;
			}
			}
	}

	return retorno;
}
