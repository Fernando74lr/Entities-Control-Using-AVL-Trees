#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Entity.h"

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
	int time_required; // in hours.
	struct client* find;
	char* word;
	int clients;
	do {
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
				root = insert(root, 10, "A"); 
				root = insert(root, 20, "B"); 
				root = insert(root, 30, "D"); 
				root = insert(root, 40, "E"); 
				root = insert(root, 50, "F"); 
				root = insert(root, 25, "C");
				printf("Preorder traversal of the constructed AVL tree is:\n"); 
				preOrder(root);
				printf("\n");
				break;
			case 2:
				break;
			case 3:
				printf("Introduce las placas del auto: \n");
				find = search(root, strdup(gets(word)));
				printf("Buscando...\n");
				printf("\nValores encontrados...\n");
				printf("Placas: ");
				print_string(find->plate);
				// printf("\nTipo de carro: "); //////empieza con NULL debida a la función insertar
				// print_string(find->car_type);
				// printf("\nTipo de servicio: ");
				// print_string(find->service_type);
				// printf("\nMecanico asignado: ");
				// print_string(find->assigned_mechanic);
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
				break;
			case 6:
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
