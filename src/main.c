#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Menu informes
	11. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flagCarga = 0;
    int opcionInformes = 0;
    int auxPasajeros = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	Passenger_MenuPrincipal();
    	utn_getNumero(&option, "\nIngrese un numero de operacion: ", "\nOpcion incorrecta. reingrese: ", 1, 11, 3);
        switch(option)
        {
            case 1:
                if (flagCarga == 0) {
                	controller_loadFromText("data.csv", listaPasajeros);
                	flagCarga = 1;
                } else {
                	printf("La lista ya ha sido cargada. \n");
                }
                break;

            case 2:
                if (flagCarga == 0) {
                	controller_loadFromBinary("data.bin", listaPasajeros);
                	flagCarga = 1;
                } else {
                	printf("La lista ya ha sido cargada. \n");
                }
                break;

            case 3:
            	controller_addPassenger(listaPasajeros);
                break;

            case 4:
            	controller_editPassenger(listaPasajeros);
                break;

            case 5:
            	controller_removePassenger(listaPasajeros);
                break;

            case 6:
            	controller_ListPassenger(listaPasajeros);
                break;

            case 7:
            	controller_sortPassenger(listaPasajeros);
                break;

            case 8:
            	controller_saveAsText("data.csv", listaPasajeros);
                break;

            case 9:
            	controller_saveAsBinary("data.bin", listaPasajeros);
                break;

            case 10:
            	do{
            		Passenger_MenuInformes();
					utn_getNumero(&opcionInformes, "\nIngrese un numero de operacion: ", "\nOpcion incorrecta. reingrese: ", 1, 4, 3);

					switch (opcionInformes)
					{
					case 1: //Informar cantidad de pasajeros por clase:
						auxPasajeros = ll_count(listaPasajeros, cantidadPasajerosFirstClass);
						printf("La cantidad de pasajeros de FirstClass es %d. \n", auxPasajeros);
						auxPasajeros = ll_count(listaPasajeros, cantidadPasajerosExecutiveClass);
						printf("La cantidad de pasajeros de ExecutiveClass es %d. \n", auxPasajeros);
						auxPasajeros = ll_count(listaPasajeros, cantidadPasajerosEconomyClass);
						printf("La cantidad de pasajeros de EconomyClass es %d. \n", auxPasajeros);
						break;

					case 2://filtrar por clase de pasajero
						Controller_Filtrar(listaPasajeros);
						break;

					case 3: //Calcular millas acumuladas:
						break;

					case 4:
						break;
					}
            	} while (opcionInformes != 4);
                break;

            case 11:
            	ll_deleteLinkedList(listaPasajeros);
            	printf("¡Hasta Luego! \n");
                break;
        }

    }while(option != 11);
    return 0;
}

