#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int mssv;
    float diem;
    struct Student* next;
} Student;

Student* createStudent(int mssv, float diem) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->mssv = mssv;
    newStudent->diem = diem;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(Student** head, int mssv, float diem) {
    // Student* newStudent = createStudent(mssv, diem);
    // newStudent->next = *head;
    // *head = newStudent;
    Student* newStudent = createStudent(mssv, diem);
    if (*head == NULL) {
        *head = newStudent;
        return;
    }
    Student* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newStudent;
}

void sortList(Student** head) {
    Student *i, *j;
    for(i = *head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->diem < j->diem) {
                float tempDiem = i->diem;
                int tempMssv = i->mssv;
                i->diem = j->diem;
                i->mssv = j->mssv;
                j->diem = tempDiem;
                j->mssv = tempMssv;
            }
        }
    }
}

void printList(Student* head) {
    Student* temp = head;
    while(temp != NULL) {
        printf("MSSV: %d, Diem: %.2f\n", temp->mssv, temp->diem);
        temp = temp->next;
    }
}

int main() {
    Student* head = NULL;
    int i, mssv;
    float diem;
    for(i = 0; i < 3; i++) {
        printf("Nhap MSSV va diem cua sinh vien thu %d: ", i+1);
        scanf("%d %f", &mssv, &diem);
        insertStudent(&head, mssv, diem);
    }
    sortList(&head);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    printList(head);
    return 0;
}