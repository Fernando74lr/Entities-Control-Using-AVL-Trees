#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Entity.h"


void Ascending_Order_Plate(struct client* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first recur on left child */
     Ascending_Order_Plate(node->left); 
  
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
  
     /* now recur on right child */
     Ascending_Order_Plate(node->right); 
}


void Descending_Order_Plate(struct client* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first recur on left child */
     Descending_Order_Plate(node->right); 
  
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
  
     /* now recur on right child */
     Descending_Order_Plate(node->left); 
}
