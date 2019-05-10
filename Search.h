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


int word_compare(struct client* node, char * word) {
	int show = 0;
	if (strcmp(node->plate, word) == 0)
		return show = 1;
	if (strcmp(node->car_type, word) == 0)
		return show = 1;
	if (strcmp(node->service_type, word) == 0)
		return show = 1;
	if (strcmp(node->assigned_mechanic, word) == 0)
		return show = 1;
	return show;
}

int length_word(char * word) {
    printf("LENGTH WORD\n");
    int n = 0;
    while(*word) {
    	n++;
    }
    return n;
}

int at_least_subword(char * word1, char * word2) {
    int n = 0;
    for (int i = 0; i < strlen(word1); ++i) {
        if (*word1 == *word2)
            n++;
        word1++;
        word2++;
    }
    if (n>=2)
    	return 1;
    else
    	return 0;
}

int subword_compare(struct client* node, char * word) {
	int show = 0;
	if (at_least_subword(node->plate, word) == 1)
		return show = 1;
	if (at_least_subword(node->car_type, word) == 1)
		return show = 1;
	if (at_least_subword(node->service_type, word) == 1)
		return show = 1;
	if (at_least_subword(node->assigned_mechanic, word) == 1)
		return show = 1;
	return show;
}

void exact_match(struct client* node, char * word) {
	struct client * temp = node;
    if(temp != NULL) {
        if (word_compare(temp, word) == 1) { //temp->disable == 0)
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
        	printf("\n");
        }
        exact_match(temp->left, word);
        exact_match(temp->right, word);
    }
}

void exact_match_substring(struct client* node, char * word) {
	struct client * temp = node;
    if(temp != NULL) {
        if (subword_compare(temp, word) == 1) {
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
        exact_match_substring(temp->left, word);
        exact_match_substring(temp->right, word);
    }
}
