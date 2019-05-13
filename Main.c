#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Entity.h"
#include "Search.h"
#include "Report.h"
<<<<<<< HEAD
=======
#include "AdministrativeTools.h"
>>>>>>> d06e2dd53304569def4e30be5b7980e4e5c0562c

void delay(int number_of_seconds) { 
    // Converting time into milli_seconds.
    int milli_seconds = 1000 * number_of_seconds; 
    // Stroing start time.
    clock_t start_time = clock(); 
    // looping till required time is not acheived.
    while (clock() < start_time + milli_seconds); 
} 

void menu_options() {
	int option, optRep;
	struct client *root = NULL;
<<<<<<< HEAD
	struct client *node;

=======
	struct client *node = root;
>>>>>>> d06e2dd53304569def4e30be5b7980e4e5c0562c
	char * plate;
	char * car_type;
	char * service_type;
	char * assigned_mechanic;
<<<<<<< HEAD
    int time_required; // in hours.
=======
    int time_required, option_6; // in hours.
    char* nombreArchivo;
    char* nombreArchivoC;
>>>>>>> d06e2dd53304569def4e30be5b7980e4e5c0562c

	struct client* find;
	int clients, p;
	char* word;
<<<<<<< HEAD
=======
	// struct node * head = NULL;

>>>>>>> d06e2dd53304569def4e30be5b7980e4e5c0562c
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
				insert_at_the_end(&node, plate, car_type, service_type, assigned_mechanic, time_required);
				// print(node);
				printf("\n");
				break;
			case 2:
				printf("Deseas solo deshabilitar o eliminar permanentemente? (0=deshabilitar, 1=eliminar): \n");
				plate = strdup(gets(word));
				if (strcmp(plate, "0") == 0) {
					printf("Placa del cliente a deshabilitar: ");
					plate = strdup(gets(word));
					root = disable_entity(root, plate);
					printf("Deshabilitado exitosamente.\n");
				} else if (strcmp(plate, "1") == 0) {
					printf("Placa del cliente a eliminar permanentemente: ");
					plate = strdup(gets(word));
					root = deleteNode(root, plate);
					printf("Eliminado permanente exitoso.\n");
				}
			    preOrder(root);
			    printf("\n");
				break;
			case 3:
				printf("Introduce las placas del auto: \n");
				find = search(root, strdup(gets(word)));
				printf("Buscando...\n");
				printf("\nValores encontrados...\n");
				printf("Placas: ");
				print_string_p(find->plate);
				printf("\nTipo de carro: "); //////empieza con NULL debida a la función insertar
				print_string_p(find->car_type);
				printf("\nTipo de servicio: ");
				print_string_p(find->service_type);
				printf("\nMecanico asignado: ");
				print_string_p(find->assigned_mechanic);
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
				print_string_p(find->plate);
				printf("\nTipo de carro: ");
				print_string_p(find->car_type);
				printf("\nTipo de servicio: ");
				print_string_p(find->service_type);
				printf("\nMecanico asignado: ");
				print_string_p(find->assigned_mechanic);
				printf("\nTiempo requerido: %i \n\n", find->time_required);

				break;
			case 4:
				printf("Placa del cliente que quieres recuperar: \n");
				plate = strdup(gets(word));
				if (search(root, plate)==NULL)
					printf("NO EXISTE\n");
				else
					root = enable_entity(root, plate);
				preOrder(root);
				printf("\n");
				break;
			case 5:
<<<<<<< HEAD
				// printf("Elige\n");
			printf("Placas: ");
			plate = strdup(gets(word));
			
			printf("Valores menores a placa\n");
			higher_values(root, plate);
			flag2=0;
				break;
			case 6:
				find = search(root, "A");
				printf("encontre: %s con tiempo: %i\n", find->plate,find->time_required);
				break;
			case 7:
				printf("Placas: ");
				plate = strdup(gets(word));
				printf("Valores menores a placa\n");
				less_values(root, plate);
				flag = 0;
=======
				printf("\nReporte Total: \n");
				printf("1. Orden Ascendente por Placas.\n");
				printf("2. Orden Descendente por Placas.\n");
				printf("3. Orden Ascendente por Tipo de Carro.\n");
				printf("4. Orden Descendente por Tipo de Carro.\n");
				printf("5. Orden Ascendente por Tipo de Servicio.\n");
				printf("6. Orden Descendente por Tipo de Servicio.\n");
				printf("7. Orden Ascendente por Mecanico Asignado.\n");
				printf("8. Orden Descendente por Mecanico Asignado.\n");
				printf("9. Orden Ascendente por Tiempo Requerido.\n");
				printf("10. Orden Descendente por Tiempo Requerido.\n");
				plate = strdup(gets(word));
				switch(atoi(plate)) {
					case 1:
						Ascending_Order_Plate(root);
						break;
					case 2:
						Descending_Order_Plate(root);
						break;
					case 3:
						ascending_sort_the_elements(&node, 1);
						print(node);
						break;
					case 4:
						descending_sort_the_elements(&node, 1);
						print(node);
						break;
					case 5:
						ascending_sort_the_elements(&node, 2);
						print(node);
						break;
					case 6:
						descending_sort_the_elements(&node, 2);
						print(node);
						break;
					case 7:
						ascending_sort_the_elements(&node, 3);
						print(node);
						break;
					case 8:
						descending_sort_the_elements(&node, 3);
						print(node);
						break;
					case 9:
						ascending_sort_the_elements(&node, 4);
						print(node);
						break;
					case 10:
						descending_sort_the_elements(&node, 4);
						print(node);
						break;
					default:
						printf("Error: inserta una opcion valida.\n");
				}
				break;
			case 6:
				printf("\nBuscar por placa.\n");
				printf("1. Valor exacto de la placa ingresada.\n");
				printf("2. Valores menores o iguales a la placa ingresada.\n");
				printf("3. Valores mayores o iguales a la placa ingresada.\n");
				printf("\nBusca una palabra en todos los campos.\n");
				printf("4. Buscar valor exacto de la palabra ingresada.\n");
				printf("5. Buscar por subcadena de texto.\n");
				plate = strdup(gets(word));
				switch(atoi(plate)) {
					case 1:
						printf("Placa a encontrar: ");
						plate = strdup(gets(word));
						find = search(root, plate);
						printf("encontre: %s con tiempo: %i\n", find->plate,find->time_required);
						break;
					case 2:
						printf("Placa: ");
						plate = strdup(gets(word));
						printf("Valores menores a placa\n");
						less_values(root, plate);
						flag = 0;
						break;
					case 3:
						printf("Placa: ");
						plate = strdup(gets(word));
						printf("Valores menores a placa\n");
						higher_values(root, plate);
						flag2=0;
						break;
					case 4:
						printf("Referencia: ");
						plate = strdup(gets(word));
						printf("Clientes con esa referencia: \n\n");
						exact_match(root, plate);
						break;
					case 5:
						printf("Referencia: ");
						plate = strdup(gets(word));
						printf("Clientes con ese pedazo de referencia: \n\n");
						exact_match_substring(root, plate);
						break;
					default:
						printf("Error: inserta una opcion valida.\n");
				}
				break;
			case 7:
				printf("	Elige entre las siguientes: \n");
				printf("	1.  Guardar respaldo de informacion \n");
				printf("	2.  Cargar informacion de un archivo de respaldo.\n");
				fflush(stdin);
				scanf("%d", &optRep);
				switch(optRep){
					case 1:
						printf("Con que nombre quieres guardar el archivo? \n");
						fflush(stdin);
						nombreArchivo = strdup(gets(word));
						strcat(nombreArchivo,".txt");
						printf("Nombre final archivo %s\n", nombreArchivo);
						guardar(nombreArchivo,root);
					break;
					case 2:
						printf("Cual es el nombre del archivo que quieres cargar?\n");
						fflush(stdin);
						nombreArchivoC = strdup(gets(word));
						strcat(nombreArchivoC,".txt");
						printf("buscare %s\n",nombreArchivoC );
						root = eliminar(root);
						printf("cargare...\n");
						root=cargar(nombreArchivoC);


					break;
					default: printf("Opcion invalida\n");
				}
>>>>>>> d06e2dd53304569def4e30be5b7980e4e5c0562c
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
