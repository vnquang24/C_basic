#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct key
{
    int vl;
    struct key* next;
    struct key* prev;
}node;
int check(node* root,int vl){ // Có tồn tại trả về 0, không tồn tại trả về 1
    node* p_run = NULL;
    for (p_run = root; p_run != NULL; p_run = p_run->next){
        if (p_run->vl == vl)
        {
            return 0;
        }
    };
    return 1;
}
node* create_node(int a){
    node* p =  (node*)malloc(sizeof(node));
    p->vl = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

node* add_node(node* root,int a){
    node* p = create_node(a);
    if (root == NULL)
    {
        return p;
    }
    node* p_run = NULL;
    for (p_run = root; p_run->next != NULL; p_run = p_run->next)
    ;
    p_run->next = p;
    p->prev = p_run;
    return root;
}

node* printll(node* root){
    node* p_run = root;
    for (p_run = root; p_run != NULL; p_run = p_run->next)
    {
        if (p_run->next == NULL)
        {
            printf("%d",p_run->vl);
        }
        else
        {
            printf("%d ",p_run->vl);

        }  
    }
    return root;
}

node* addlast(node* root,int k){
    if (check(root,k) == 0)
    {
        return root;
    }
    else {
        node* p = create_node(k);
        if (root == NULL) return p;
        node* p_run;   
        for (p_run = root; p_run->next != NULL; p_run = p_run->next)
        ;
        p_run->next = p;
        return root;
    }   
}
node* addfirst(node* root,int k){
    if (check(root,k) == 0)
    {
        return root;
    }
    else{
        node* p = create_node(k);
        p->next = root;
        return p;
    }   
}

node* addafter(node* root,int u,int v){
    if (check(root,u) == 0 || check(root,v) == 1)
    {
        return root;
    }
    else
    {
        // node* p = create_node(u);
        // node* p_run = NULL;
        // for (p_run = root;p_run != NULL;p_run = p_run->next) // Không giữ được giá trị next của con trỏ
        // Hàm for công p_run trước rồi mới check nhưng khi dùng while thì lại khác có thể kiểm soát được lúc tăng giá trị của con trỏ p_run
        // {
        //     if (p_run->vl == v)
        //     {
        //         p = p_run->next;
        //         p_run->next = p;
        //         break;
        //     }
        // }  
        node* p_run = root;
        while (p_run != NULL) {
            if (p_run->vl == v) {
                // Tìm thấy phần tử có giá trị v, thêm u vào sau nó
                node* p = create_node(u);
                p->next = p_run->next;
                p_run->next = p;
                break;
            }
            p_run = p_run->next;
        }
        return root;
    }
    return root;
}

node* addbefore(node* root,int u,int v){
    if (check(root,u) == 0 || check(root,v) == 1)
    {
        return root;
    }
    else{
        // node* p_run = root;
        // while (p_run != NULL)
        // {
        //     if ((p_run->next)->vl == v) // Nếu v là giá trị đầu tiên đổ bể luôn XD
        //     {
        //         node* p = create_node(u); 
        //         p = p_run->next; // Tư duy rất hợp lí nhưng không chạy được thôi qua phương án đánh dấu pre
        //         p_run->next = p;
        //         break;
        //     }
        //     p_run = p_run->next;
        // }
        // return root;
        node* p_run = root;
        node* prev = NULL; 
        while (p_run != NULL) {
            if (p_run->vl == v) {
                node* p = create_node(u);
                p->next = p_run;
                if (prev != NULL) {
                    prev->next = p;
                } else {
                    root = p; 
                }
                break;
            }
            prev = p_run;
            p_run = p_run->next;
        }
        return root;
    }
}
node* removenode(node* root,int k){
    node* p_run = root;
    node* prev = NULL;
        while (p_run != NULL) {
            if (p_run->vl == k) {
                if (prev != NULL) {
                    prev->next = p_run->next;
                    return root;
                } else {
                    root = p_run->next;
                    return root; 
                }
                break;
            }
            prev = p_run;
            p_run = p_run->next;
        }
        return root;
}

node* reserve(node* root){
    node* cur = root; 
    node* prev = NULL;
    node* next = NULL;
    while (cur != NULL) {
        next = cur->next;  // Lưu giữ con trỏ tiếp theo của nút hiện tại
        cur->next = prev;   // Đảo ngược liên kết của nút hiện tại
        prev = cur;         // Cập nhật con trỏ prev
        cur = next;         // Di chuyển đến nút tiếp theo
    }
    return prev;  // Trả về danh sách đã được đảo ngược
}
int main(){
    int n,temp;
    node* root = NULL;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        root = add_node(root,temp);
    }    
  //  root = addlast(root,k); // check 
  //  root = addfirst(root,4); // check
 //   root = addafter(root,4,2); // check
 //     root = addbefore(root,6,2); // check
 //    root = removenode(root,1); // check
     char command[10];
    int u, v;
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &temp);
            root = addlast(root, temp);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &temp);
            root = addfirst(root, temp);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &u, &v);
            root = addafter(root, u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &u, &v);
            root = addbefore(root, u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &temp);
            root = removenode(root, temp);
        } else if (strcmp(command, "reverse") == 0) {
            root = reserve(root);
        } else if (strcmp(command, "#") == 0) {
            break; // Đọc dòng kết thúc và thoát khỏi vòng lặp
        }
    }

    printll(root);
    return 0;
}
