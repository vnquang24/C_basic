#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char tele[50];
    char add[50];
    struct node* next;
}node;

node* create_node(char x[],char y[],char z[]){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->name,x);
    strcpy(p->add,z);
    strcpy(p->tele,y);
    p->next = NULL;
    return p;   
}

node* push(node* root,char x[],char y[],char z[]){
    node* p = create_node(x,y,z);
    if (root == NULL)
    {
        return p;
    }
    p->next = root;
    return p;
}

node* find(node* root,char x[]){
    node *prev = NULL, *current = root;
    while (current != NULL) {
        if (strcmp(current->name, x) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
                current->next = root;
                root = current;
            }
            return root;
        }
        prev = current;
        current = current->next;
    }
    return root;
}

void print_ll(node* root){
    for (node* p_run = root;p_run != NULL;p_run = p_run->next){
        printf("%s %s %s\n",p_run->name,p_run->tele,p_run->add);
    };
}

void free_list(node* root){
    node* tmp;

    while (root != NULL)
    {
       tmp = root;
       root = root->next;
       free(tmp);
    }
}

int main(){
    node* root = NULL;
    char key[50];
    char temp1[50];
    char temp2[50];
    char temp3[50];
    char line[150];

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%s %s %s", temp1, temp2, temp3) == 3) {
            root = push(root, temp1, temp2, temp3);
        } else if (strcmp(temp1, "#") == 0) {
            break;
        }
    }

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%s", key);
    root = find(root,key);
    node *result = root;
    if (result == NULL || strcmp(result->name, key) != 0) printf("Not found\n");
    else printf("0 %s %s %s\n", result->name, result->tele, result->add);
    print_ll(root);  
    free_list(root);
    return 0; 
}