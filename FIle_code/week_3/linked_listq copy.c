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

void swapNodes(Student** head_ref, Student* currX, Student* currY, Student* prevX, Student* prevY) {
    if (currX == currY) return;
    if (prevX != NULL) prevX->next = currY;
    else *head_ref = currY;
    if (prevY != NULL) prevY->next = currX;
    else *head_ref = currX;
    Student* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void sortList(Student** head) {
    Student *prevX = NULL, *currX = *head;
    while (currX != NULL) {
        Student *prevY = NULL, *currY = *head;
        while (currY != NULL) {
            if (currX->diem > currY->diem) {
                swapNodes(head, currX, currY, prevX, prevY);
                Student* temp = currX;
                currX = currY;
                currY = temp;
            }
            prevY = currY;
            currY = currY->next;
        }
        prevX = currX;
        currX = currX->next;
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
    for(i = 0; i < 10; i++) {
        printf("Nhap MSSV va diem cua sinh vien thu %d: ", i+1);
        scanf("%d %f", &mssv, &diem);
        insertStudent(&head, mssv, diem);
    }
    sortList(&head);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    printList(head);
    return 0;
}