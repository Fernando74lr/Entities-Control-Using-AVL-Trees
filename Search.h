#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Entity.h"


struct client* search(struct client* root, char* find){
	printf("buscando mas...\n");
	if(strcmp(root->plate,find) == 0){
		return root;
	}
	else if(strcmp(root->plate,find) <0){
		return search(root->right, find);
	}
	else if(strcmp(root->plate,find) >0)
		return search(root->left, find);
	else
		printf("No encontrado\n");
		return NULL;
}

