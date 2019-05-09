#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Entity.h"
#include "Search.h"

void delay(int number_of_seconds) { 
    // Converting time into milli_seconds.
    int milli_seconds = 1000 * number_of_seconds; 
    // Stroing start time.
    clock_t start_time = clock(); 
    // looping till required time is not acheived.
    while (clock() < start_time + milli_seconds); 
} 

void menu_options() {
	int option;
	struct client *root = NULL;

	char * plate;
	char * car_type;
	char * service_type;
	char * assigned_mechanic;
    int time_required; // in hours.

	struct client* find;
	int clients, p;
	char* word;
	do {
		fflush(stdin);
		printf("\nMenu:\n");
		printf("0. Salir\n");
		printf("1. Insertar nueva entidad.\n");
		printf("2. Borrar una entidad.\n");
		printf("3. Editar una entidad.\n");
		printf("4. Recuperar una entidad borrada.\n");
		printf("5. Reporte total.\n");
		printf("6. Buscar.\n");
		printf("7. Herramientas administrativas.\n");
		printf("\nOpcion: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option) {
			case 0:
				// save(); | Auto save without asking.
				printf("\nAnalizando entidad...\n");
				delay(2);
				printf("\nGuardando...\n");
				delay(2);
				printf("\nGuardado exitosamente. Hasta luego.\n");
				delay(1);
				break;
			case 1:
				printf("\nIntroduce los datos...\n\n");
				printf("Placa: ");
				plate = strdup(gets(word));
				printf("Tipo de carro: ");
				car_type = strdup(gets(word));
				printf("Tipo de servicio: ");
				service_type = strdup(gets(word));
				printf("Mecanico asignado: ");
				assigned_mechanic = strdup(gets(word));
				fflush(stdin);
				printf("Tiempo requerido: ");
				scanf("%d",&time_required);
				root = insert(root, plate ,car_type, service_type, assigned_mechanic, time_required);
				printf("El ordenamiento previo del recorrido del arbol AVL construido es:\n"); 
				preOrder(root);
				printf("\n");
				break;
			case 2:
				printf("Placa del cliente a eliminar: ");
			    root = deleteNode(root, strdup(gets(plate)));
			    printf("Eliminado exitosamente.\n");
			    preOrder(root);
			    // fflush(stdin);
			    printf("\n");
				break;
			case 3:
				printf("Introduce las placas del auto: \n");
				find = search(root, strdup(gets(word)));
				printf("Buscando...\n");
				printf("\nValores encontrados...\n");
				printf("Placas: ");
				print_string(find->plate);
				printf("\nTipo de carro: "); //////empieza con NULL debida a la función insertar
				print_string(find->car_type);
				printf("\nTipo de servicio: ");
				print_string(find->service_type);
				printf("\nMecanico asignado: ");
				print_string(find->assigned_mechanic);
				printf("\nTiempo requerido: %i \n\n", find->time_required);

				printf("Introduce los nuevos valores...\n");
				printf("\nTipo de carro: ");
				find->car_type = strdup(gets(word));
				printf("\nTipo de servicio: ");
				find->service_type = strdup(gets(word));
				printf("\nMecanico asignado: ");
				find->assigned_mechanic = strdup(gets(word));
				fflush(stdin);
				printf("\nTiempo requerido: ");
				scanf("%d",&time_required);
				find->time_required = time_required;

				printf("\nValores nuevos...\n");
				printf("Placas: ");
				print_string(find->plate);
				printf("\nTipo de carro: ");
				print_string(find->car_type);
				printf("\nTipo de servicio: ");
				print_string(find->service_type);
				printf("\nMecanico asignado: ");
				print_string(find->assigned_mechanic);
				printf("\nTiempo requerido: %i \n\n", find->time_required);

				break;
			case 4:
				break;
			case 5:
				printf("Elige\n");
				break;
			case 6:

				find = search(root, "A");
				printf("encontre: %s con tiempo: %i\n", find->plate,find->time_required);
				break;
			case 7:
				break;
			default:
				printf("Error: inserta una opcion valida.\n");
		}
	} while(option!=0);
}

int main(int argc, char const *argv[]) {

	menu_options();

	return 0;
}
