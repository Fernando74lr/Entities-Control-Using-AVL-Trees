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
	char * plates_ba = malloc(sizeof(char) * 1024);
	char * plate = plates_ba;
	struct client *ba_root = root;
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