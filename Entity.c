#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client { 
    int height_tree;
    int enable;
    int time_required; // in hours.
    char * plate; // Example: TXG-D93
    char * car_type; // sedan, truck, familmedium, pick-up, etc.
    char * service_type; // 15, 30 or 50 km
    char * assigned_mechanic;
    struct client *left;
    struct client *right;
};

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
struct client* create_client(int time_required, char * plate) { 
    struct client* client = (struct client*) malloc(sizeof(struct client)); 
    client->time_required = time_required;
    client->plate = plate;
    client->car_type = NULL;
    client->service_type = NULL;
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
struct client* insert(struct client* client, int time_required, char * plate) {
    /* 1.  Perform the normal BST insertion */
    if (client == NULL) 
        return(create_client(time_required, plate)); 
  
    // -------------------BORRAR DE AQUÍ-------------------

    // if (time_required < client->time_required) 
    //     client->left  = insert(client->left, time_required, plate); 
    // else if (time_required > client->time_required) 
    //     client->right = insert(client->right, time_required, plate); 
    // else // Equal time_requireds are not allowed in BST 
    //     return client;

    // -------------------BORRAR HASTA AQUÍ-------------------

    if (strcmp(plate, client->plate) < 0) 
        client->left  = insert(client->left, time_required, plate); 
    else if (strcmp(plate, client->plate) > 0) 
        client->right = insert(client->right, time_required, plate); 
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

// A utilitmedium function to print preorder traversal 
// of the tree. 
// The function also prints height_tree of evermedium client 
void preOrder(struct client *root) {
struct client * temp = root;
    if(temp != NULL) {
        printf("| ");
        print_string(temp->plate);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
  
/* Drier program to test above function*/
int main() {
  struct client *root = NULL;
  char * plates_ba = malloc(sizeof(char) * 1024);
  char * plate = plates_ba;
  struct client *ba_root = root;
  int clients;
  // for (int i = 0; i < clients; ++i) {
  //   printf("Inserta nuevo cliente (placa):\n");
  //   fgets(plate, 1023, stdin);
  //   root = insert(ba_root, i, plate);
  //   printf("Preorder traversal of the constructed AVL tree is:\n"); 
  //   preOrder(root); 
  //   plate++;
  // }

  /* Constructing tree given in the above figure */
  root = insert(root, 10, "A"); 
  root = insert(root, 20, "B"); 
  root = insert(root, 30, "D"); 
  root = insert(root, 40, "E"); 
  root = insert(root, 50, "F"); 
  root = insert(root, 25, "C");
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */


  printf("Preorder traversal of the constructed AVL tree is:\n"); 
  preOrder(root); 
  
  return 0; 
} 

// #include <stdio.h> 
// #include <stdlib.h> 

// int main(int argc, char const *argv[]) {
//     char * word = words_ba;
//     fgets(word, 1023, stdin);
//     fflush(stdin);




//     return 0;
// }