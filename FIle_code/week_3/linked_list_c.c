#include<stdio.h>
#include<stdlib.h>

typedef struct sv
{
    int mssv;
    int diem;
}sv;

typedef struct ll
{
     sv data;
     struct ll *next;
} llsv_t, *llsv_root_t;

llsv_t* create_node(){
    printf("Nhap thong tin sv: \n");
    int mssv; scanf("%d",&mssv);
    int diem; scanf("%d",&diem);
    llsv_t* newNode = (llsv_t*)malloc(sizeof(llsv_t)); 
    newNode->data.mssv = mssv;
    newNode->data.diem = diem;
    newNode->next = NULL;
    return newNode;
}

llsv_t* insert_after(llsv_root_t root,llsv_t* now){
     if (now == NULL) return root;
     llsv_t* newNode = create_node();
     now->next = newNode;
     return newNode;
}

void show_value(llsv_t* now){
     printf("MSSV: %d",now->data.mssv);
     printf("Diem: %d",now->data.diem);
}

// void swap(llsv_root_t* root,llsv_t* sv1,llsv_t* sv2){
//      llsv_t *prenode_1 = NULL;
//      llsv_t *prenode_2 = NULL;
//      llsv_t *temp = root;

//      while (temp->next != sv1->next){
//         temp = temp->next;
//         prenode_1->next = temp->next;
//      }

//     temp = root;
//      while (temp->next != sv2->next){
//         temp = temp->next;
//         prenode_2->next = temp->next;
//      }

//     if (prenode_1 != NULL)
//     {
//         prenode_1->next = sv2->next;
//     }
//     if (prenode_2 != NULL)
//     {
//         prenode_2->next = sv1->next;
//     }
//     llsv_t *tempNext = sv1;
//     sv1->next = sv2->next;
//     sv2->next = temp->next;     
// }

// void swap(llsv_t** root, llsv_t* sv1, llsv_t* sv2){
//     llsv_t *temp = *root;
//     if(sv1 == *root){
//         *root = sv2;
//         sv2->next = sv1->next;
//         sv1->next = sv2;
//     } else {
//         while(temp->next != sv1){
//             temp = temp->next;
//         }
//         temp->next = sv2;
//         sv1->next = sv2->next;
//         sv2->next = sv1;
//     }
// }
void swap(llsv_t** root, llsv_t* sv1, llsv_t* sv2){
    if (*root == NULL || sv1 == NULL || sv2 == NULL || sv1 == sv2) return;

    llsv_t **sv1_prev = root;
    while ((*sv1_prev) != sv1 && (*sv1_prev) != NULL) {
        sv1_prev = &((*sv1_prev)->next);
    }

    llsv_t **sv2_prev = root;
    while ((*sv2_prev) != sv2 && (*sv2_prev) != NULL) {
        sv2_prev = &((*sv2_prev)->next);
    }

    if (*sv1_prev == NULL || *sv2_prev == NULL) return;

    llsv_t *temp = sv2->next;
    *sv2_prev = sv1;
    *sv1_prev = sv2;
    sv2->next = sv1->next;
    sv1->next = temp;
}
// void sap_xep(llsv_root_t* root){
//     llsv_t *count = root;
//     llsv_t *count2 = root;
//     do
//     {
//         count2 = count;
//         do
//         {
//             if (count->data.diem < count2->data.diem)
//             {
//                 swap(root,count,count2);
//             }
//             count2 = count2->next;
//         }while (count2->next != NULL);
        
//     }while (count->next != NULL);
// }
void sap_xep(llsv_t** root){
    llsv_t *count = *root;
    llsv_t *count2 = NULL;
    do
    {
        count2 = count->next;
        do
        {
            if (count->data.diem < count2->data.diem)
            {
                swap(root,count,count2);
            }
            count2 = count2->next;
        }while (count2 != NULL);
        count = count->next;
    }while (count != NULL);
}
int main(){
    llsv_root_t root = NULL;
    llsv_t* temp = NULL;
    for(int i = 0; i < 3; i++){
        if(root == NULL){
            root = create_node();
            temp = root;
        } else {
            temp = insert_after(root, temp);
        }
    }
    sap_xep(&root);
    temp = root;
    while(temp != NULL){
        show_value(temp);
        temp = temp->next;
    }
    return 0;

}
