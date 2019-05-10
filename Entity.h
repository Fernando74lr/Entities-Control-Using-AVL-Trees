#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "Search.h"

struct client { 
    int height_tree;
    int disable;
    char * plate; // Example: TXG-D93
    char * car_type; // sedan, truck, familmedium, pick-up, etc.
    char * service_type; // 15, 30 or 50 km
    char * assigned_mechanic;
    int time_required; // in hours.
    struct client *left;
    struct client *right;
    struct client *next;
};

// struct node {
//     struct client * info;
//     struct node * next;
// };

struct client* search(struct client* root, char* find);
// A utilitmedium function to get maximum of two integers 
int max(int a, int b); 
  
// A utilitmedium function to get the height_tree of the tree 
int height_tree(struct client * node) { 
    if (node == NULL) 
        return 0;
    return node->height_tree;
} 
  
// A utilitmedium function to get maximum of two integers 
int max(int a, int b) { 
    return (a > b)? a : b; 
} 
  
/* Helper function that allocates a new client with the given time_required and 
    NULL left and right pointers. */
struct client* create_client(char * plate, char * car_type, char * service_type, char * assigned_mechanic, int time_required) { 
    struct client* client = (struct client*) malloc(sizeof(struct client)); 
    client->plate = plate;
    client->car_type = car_type;
    client->service_type = service_type;
    client->assigned_mechanic = assigned_mechanic;
    client->time_required = time_required;
    client->disable = 0;
    client->left = NULL; 
    client->right = NULL; 
    client->height_tree = 1;  // new client is initiallmedium added at leaf 
    return(client); 
} 
  
// A utilitmedium function to right rotate subtree rooted with medium 
// See the diagram given above. 
struct client *rotate_right(struct client *medium) { 
    struct client *minor = medium->left; 
    struct client *temp = minor->right; 
  
    // Perform rotation 
    minor->right = medium; 
    medium->left = temp; 
  
    // Update height_trees 
    medium->height_tree = max(height_tree(medium->left), height_tree(medium->right))+1; 
    minor->height_tree = max(height_tree(minor->left), height_tree(minor->right))+1; 
  
    // Return new root 
    return minor; 
} 
  
// A utilitmedium function to left rotate subtree rooted with x 
// See the diagram given above. 
struct client *rotate_left(struct client *minor) { 
    struct client *medium = minor->right; 
    struct client *temp = medium->left; 
  
    // Perform rotation 
    medium->left = minor; 
    minor->right = temp; 
  
    //  Update height_trees 
    minor->height_tree = max(height_tree(minor->left), height_tree(minor->right))+1; 
    medium->height_tree = max(height_tree(medium->left), height_tree(medium->right))+1; 
  
    // Return new root 
    return medium; 
} 
  
// Get Balance factor of client N 
int getBalance(struct client *node) {
    if (node == NULL) 
        return 0;
    return height_tree(node->left) - height_tree(node->right); 
} 
  
// Recursive function to insert a time_required in the subtree rooted 
// with client and returns the new root of the subtree. 
struct client* insert(struct client* client, char * plate, char * car_type, char * service_type, char * assigned_mechanic, int time_required) {
    /* 1.  Perform the normal BST insertion */
    if (client == NULL) 
        return(create_client(plate, car_type, service_type, assigned_mechanic, time_required)); 
  
    // -------------------BORRAR DE AQUÍ-------------------

    // if (time_required < client->time_required) 
    //     client->left  = insert(client->left, time_required, plate); 
    // else if (time_required > client->time_required) 
    //     client->right = insert(client->right, time_required, plate); 
    // else // Equal time_requireds are not allowed in BST 
    //     return client;

    // -------------------BORRAR HASTA AQUÍ-------------------

    if (strcmp(plate, client->plate) < 0) 
        client->left  = insert(client->left, plate, car_type, service_type, assigned_mechanic, time_required); 
    else if (strcmp(plate, client->plate) > 0) 
        client->right = insert(client->right, plate, car_type, service_type, assigned_mechanic, time_required);
    else {
        printf("Ya existe el cliente que quieres agregar.\n");
        return client;
    } 
  
    /* 2. Update height_tree of this ancestor client */
    client->height_tree = 1 + max(height_tree(client->left), height_tree(client->right));
  
    /* 3. Get the balance factor of this ancestor 
          client to check whether this client became 
          unbalanced */
    int balance = getBalance(client); 
  
    // If this client becomes unbalanced, then 
    // there are 4 cases 
    
    // -------------------BORRAR DE AQUÍ-------------------
    // // Left Left Case 
    // if (balance > 1 && time_required < client->left->time_required) 
    //     return rotate_right(client); 
  
    // // Right Right Case 
    // if (balance < -1 && time_required > client->right->time_required) 
    //     return rotate_left(client); 
  
    // // Left Right Case 
    // if (balance > 1 && time_required > client->left->time_required) 
    // { 
    //     client->left =  rotate_left(client->left); 
    //     return rotate_right(client); 
    // } 
  
    // // Right Left Case 
    // if (balance < -1 && time_required < client->right->time_required) 
    // { 
    //     client->right = rotate_right(client->right); 
    //     return rotate_left(client); 
    // } 
    // -------------------BORRAR HASTA AQUÍ-------------------

    // Left Left Case 
    if (balance > 1 && (strcmp(plate, client->left->plate) < 0))
        return rotate_right(client); 
  
    // Right Right Case 
    if (balance < -1 && (strcmp(plate, client->right->plate) > 0))
        return rotate_left(client); 
  
    // Left Right Case 
    if (balance > 1 && (strcmp(plate, client->left->plate) > 0)) {
        client->left =  rotate_left(client->left); 
        return rotate_right(client); 
    } 
  
    // Right Left Case 
    if (balance < -1 && (strcmp(plate, client->right->plate) < 0)) {
        client->right = rotate_right(client->right); 
        return rotate_left(client); 
    } 

    /* return the (unchanged) client pointer */
    return client; 
}

// print a "String".
void print_string(char * word) {
    char * ptc = word;
    while(*ptc) {
        printf("%c ", *ptc);
        ptc++;
    }
}

void print_string_p(char * word) {
    char * ptc = word;
    while(*ptc) {
        printf("%c", *ptc);
        ptc++;
    }
}

// A utilitmedium function to print preorder traversal 
// of the tree.
// The function also prints height_tree of evermedium client 
void preOrder(struct client *root) {
struct client * temp = root;
    if(temp != NULL) {
        if (temp->disable == 0) {
            printf("| ");
            print_string(temp->plate);
        }
        // else {
        //     printf("| BORRADO: ");
        //     print_string(temp->plate);
        // }
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

/* Given a non-empty binary search tree, return the 
   node with minimum time_required value found in that tree. 
   Note that the entire tree does not need to be 
   searched. */
struct client * minValueNode(struct client* node) {
    struct client* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
}
  
// Recursive function to delete a node with given time_required 
// from subtree with given root. It returns root of 
// the modified subtree.

struct client* disable_entity(struct client* root, char * plate) {
    struct client * temp;
    temp = search(root, plate);
    temp->disable = 1;
    return root;
}

struct client* enable_entity(struct client* root, char * plate) {
    struct client * temp;
    temp = search(root, plate);
    temp->disable = 0;
    return root;
}

struct client* deleteNode(struct client* root, char * plate) {
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root;

    // If the time_required to be deleted is smaller than the 
    // root's time_required, then it lies in left subtree 
    if (strcmp(plate, root->plate) < 0)
        root->left = deleteNode(root->left, plate); 
  
    // If the time_required to be deleted is greater than the 
    // root's time_required, then it lies in right subtree 
    else if(strcmp(plate, root->plate) > 0)
        root->right = deleteNode(root->right, plate); 

    // if time_required is same as root's time_required, then This is 
    // the node to be deleted 
    else {
        // node with only one child or no child 
        if((root->left == NULL) || (root->right == NULL)) {
            struct client *temp = root->left ? root->left : root->right; 
  
            // No child case 
            if (temp == NULL) {
                temp = root; 
                root = NULL; 
            }
            else // One child case 
                *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else {
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct client* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->disable = 0;
            root->plate = temp->plate;
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->plate);
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
        return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height_tree = 1 + max(height_tree(root->left), height_tree(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rotate_right(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return rotate_left(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotate_right(root->right); 
        return rotate_left(root); 
    } 
  
    return root; 
}

// insert an item at the end of the list.
void insert_at_the_end(struct client * * pthead, char * plate, char * car_type, char * service_type, char * assigned_mechanic, int time_required) {
    // printf("INSERTANDO 2....\n");

    struct client * temp = malloc(sizeof(struct client));
    struct client * last_next = *pthead;

    if (*pthead == NULL) {
        *pthead = temp;
        temp->plate = strdup(plate);
        temp->car_type = strdup(car_type);
        temp->service_type = strdup(service_type);
        temp->assigned_mechanic = strdup(assigned_mechanic);
        temp->time_required = time_required;
        temp->next = NULL;
    }
    else {
        // printf("INSERTANDO 3....\n");
        while(last_next->next != NULL) {
            last_next = last_next->next;
        }
        last_next->next = temp;
        temp->plate = strdup(plate);
        temp->car_type = strdup(car_type);
        temp->service_type = strdup(service_type);
        temp->assigned_mechanic = strdup(assigned_mechanic);
        temp->time_required = time_required;
        temp->next = NULL;
    }
}

void print(struct client * item) {
    struct client * temp = item;
    while(temp) {
        printf("---------------------------------------------\n");
        printf("Placas: ");
        print_string_p(temp->plate);
        printf("\nTipo de carro: ");
        print_string_p(temp->car_type);
        printf("\nTipo de servicio: ");
        print_string_p(temp->service_type);
        printf("\nMecanico asignado: ");
        print_string_p(temp->assigned_mechanic);
        printf("\nTiempo requerido: %i\n", temp->time_required); 
        printf("---------------------------------------------\n");
        // printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

// void recursive_print(struct client * pthead) {
//     // printf("IMPRIMIENDO....\n");
//     if (pthead != NULL) {
//         printf("  ->  ");
//         // if (strcmp(field, "placa") == 0)
//             print_string_p(pthead->assigned_mechanic);
//         // if (strcmp(field, "coche") == 0)
//         //     print_string_p(pthead->car_type);
//         // if (strcmp(field, "servicio") == 0)
//         //     print_string_p(pthead->service_type);
//         // if (strcmp(field, "mecanico") == 0)
//         //     print_string_p(pthead->assigned_mechanic);
//         recursive_print(pthead=pthead->next);
//     }
//     else
//         printf("\n");
// }

void ascending_sort_the_elements(struct client * * pthead, int which_one) {
    for (int i = 0; i < 5; ++i) {
        char * temp;
        int temp_int;
        struct client * first = *pthead;
        struct client * second;
        while (first->next) {
            second = first->next;
            if (pthead == NULL)
                printf("NULL\n");
            else {
                switch(which_one) {
                    case 1:
                        if (strcmp(first->car_type, second->car_type) >= 0) {
                            // ----
                            temp = strdup(first->plate);
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = strdup(first->car_type);
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = strdup(first->service_type);
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = strdup(first->assigned_mechanic);
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 2:
                        if (strcmp(first->service_type, second->service_type) >= 0) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 3:
                        if (strcmp(first->assigned_mechanic, second->assigned_mechanic) >= 0) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 4:
                        if (first->time_required >= second->time_required) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    default:
                        printf("Error: inserta una opcion valida.\n");
                }
            }
            first = first->next;
        }
    }
}

void descending_sort_the_elements(struct client * * pthead, int which_one) {
    for (int i = 0; i < 5; ++i) {
        char * temp;
        int temp_int;
        struct client * first = *pthead;
        struct client * second;
        while (first->next) {
            second = first->next;
            if (pthead == NULL)
                printf("NULL\n");
            else {
                switch(which_one) {
                    case 1:
                        if (strcmp(first->car_type, second->car_type) <= 0) {
                            // ----
                            temp = strdup(first->plate);
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = strdup(first->car_type);
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = strdup(first->service_type);
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = strdup(first->assigned_mechanic);
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 2:
                        if (strcmp(first->service_type, second->service_type) <= 0) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 3:
                        if (strcmp(first->assigned_mechanic, second->assigned_mechanic) <= 0) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    case 4:
                        if (first->time_required <= second->time_required) {
                            // ----
                            temp = first->plate;
                            first->plate = second->plate;
                            second->plate = strdup(temp);
                            // ----
                            temp = first->car_type;
                            first->car_type = second->car_type;
                            second->car_type = strdup(temp);
                            // ----
                            temp = first->service_type;
                            first->service_type = second->service_type;
                            second->service_type = strdup(temp);
                            // ----
                            temp = first->assigned_mechanic;
                            first->assigned_mechanic = second->assigned_mechanic;
                            second->assigned_mechanic = strdup(temp);
                            // ----
                            temp_int = first->time_required;
                            first->time_required = second->time_required;
                            second->time_required = temp_int;
                        }
                        break;
                    default:
                        printf("Error: inserta una opcion valida.\n");
                }
            }
            first = first->next;
        }
    }
}

// void insert_linked_list(struct client *root) {
//     struct client * temp_client = root;
//     if(temp_client != NULL) {
//         printf("INSERTANDO....\n");
//         insert_at_the_end(&temp_client, temp_client->plate, temp_client->car_type, temp_client->service_type, temp_client->assigned_mechanic, temp_client->time_required);
//         insert_linked_list(temp_client->left);
//         insert_linked_list(temp_client->right);
//     }
// }
