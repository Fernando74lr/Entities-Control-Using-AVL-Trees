#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total;

void numDatos(struct client* node) 
{ 
    if (node == NULL) 
    	return ; 
    /* first recur on left child */
    numDatos(node->right); 
    /* then print the data of node */
    total++;
    /* now recur on right child */
    numDatos(node->left); 
}

void guardarPreorder(struct client* node, FILE * archivo, char* time) 
{ 
    if (node == NULL) 
          return; 
  
     /* first print data of node */
    fputs(node->plate,archivo);
    printf("agregue placa\n");
    fputs("\n",archivo);
    fputs(node->car_type,archivo);
    printf("agregue tipo de carro\n");
    fputs("\n",archivo);
    fputs(node->service_type,archivo);
    printf("agregue tipo de servicio\n");
    fputs("\n",archivo);
    fputs(node->assigned_mechanic,archivo);
    printf("agregue mecanico\n");
    fputs("\n",archivo);
    sprintf(time, "%d", node->time_required);
    printf("agregue tiempo\n");
    fputs(time,archivo);
    printf("agregue tipo de servicio 2\n");
    fputs("\n",archivo);
  
     /* then recur on left sutree */
     guardarPreorder(node->left, archivo, time);   
  
     /* now recur on right subtree */
     guardarPreorder(node->right, archivo, time); 
} 


void guardar(char* nombreArchivo, struct client* root){
	FILE * archivo;
	char* time;
	
	archivo=fopen(nombreArchivo,"w");

	guardarPreorder(root,archivo,time);

	fclose(archivo);
}



// void cargarPreorder(FILE * archivo, struct client* root){
// 	char * plate;
// 	char * car_type;
// 	char * service_type;
// 	char * assigned_mechanic;
//     char * time_required; // in hours.

// 	if(archivo != NULL){
// 		while(!feof(archivo)){
// 			fgets (plate, 1024, archivo);
//     		fgets (car_type, 1024, archivo);
//     		fgets (service_type, 1024, archivo);
//     		fgets (assigned_mechanic, 1024, archivo);
//     		fgets (time_required, 1024, archivo);
//     		root = insert(root, plate ,car_type, service_type, assigned_mechanic, time_required);
// 			printf("El ordenamiento previo del recorrido del arbol AVL construido es:\n"); 
// 			preOrder(root);
// 			printf("\n");
// 		}


// 	}

// }




struct client* eliminar(struct client* root){
	total=0;
	numDatos(root);
	for (int i = 0; i < total; ++i)
	{
		printf("elimine: %s\n", root->plate);
		root = deleteNode(root, root->plate);
		//printf("elimine: &s\n", root->plate);
	}
	printf("termine\n");
	return NULL;
}

struct client* cargar(char* nombre){
	struct client* root=NULL;
	FILE * archivo;
	char plate[128];
	char car_type[128];
	char service_type[128];
	char assigned_mechanic[128];
	char time_required[128];
	int time;
	archivo=fopen(nombre,"r");
	if(archivo != NULL){
		printf("encontre el archivo\n");
		while(!feof(archivo)){
			fgets (plate, 128, archivo);
    		fgets (car_type, 128, archivo);
    		fgets (service_type, 128, archivo);
    		fgets (assigned_mechanic, 128, archivo);
    		fgets (time_required, 128, archivo);
    		time=atoi(strdup(time_required));
    		root = insert(root, strdup(plate) ,strdup(car_type), strdup(service_type), strdup(assigned_mechanic), time);
			printf("El ordenamiento previo del recorrido del arbol AVL construido es:\n"); 
			preOrder(root);
			printf("\n");
		}

	fclose(archivo);

	return root;


	}
}
