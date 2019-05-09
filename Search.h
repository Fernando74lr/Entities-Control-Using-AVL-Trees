#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "Entity.h"
int flag = 0;
int flag2 = 0;

struct client* search(struct client* root, char* find) {
    // printf("buscando mas...\n");
    if (root == NULL) {
        printf("No encontrado\n");
        return NULL;
    }
    if(strcmp(root->plate,find) == 0){
        return root;
    }
    else if(strcmp(root->plate,find) <0){
        return search(root->right, find);
    }
    else
        return search(root->left, find);
}

void higher_values(struct client* node, char * plate) {
     if (node == NULL) 
          return; 
  
    /* first recur on left child */
    higher_values(node->left, plate);
    if (strcmp(node->plate, plate) == 0){ 
    	flag2 = 1;
    }
    if (flag2==1){
	     /* then print the data of node */
	    printf("---------------------------------------------\n");
	    printf("Placas: ");
		print_string_p(node->plate);
		printf("\nTipo de carro: ");
		print_string_p(node->car_type);
		printf("\nTipo de servicio: ");
		print_string_p(node->service_type);
		printf("\nMecanico asignado: ");
		print_string_p(node->assigned_mechanic);
		printf("\nTiempo requerido: %i \n\n", node->time_required); 
		printf("---------------------------------------------\n");
		printf("\n\n");
    }
  
     /* now recur on right child */
     higher_values(node->right, plate); 
}

void less_values(struct client* node, char * plate) {
     if (node == NULL) 
          return; 
  
    /* first recur on left child */
    less_values(node->left, plate);
    if (flag==1){ 
    	return;
    }

     /* then print the data of node */
    printf("---------------------------------------------\n");
    printf("Placas: ");
	print_string(node->plate);
	printf("\nTipo de carro: ");
	print_string(node->car_type);
	printf("\nTipo de servicio: ");
	print_string(node->service_type);
	printf("\nMecanico asignado: ");
	print_string(node->assigned_mechanic);
	printf("\nTiempo requerido: %i \n\n", node->time_required); 
	printf("---------------------------------------------\n");
	printf("\n\n");

	if (strcmp(node->plate, plate) == 0 || flag==1){ 
		flag = 1;
		return;
	}
  
     /* now recur on right child */
     less_values(node->right, plate); 
}
