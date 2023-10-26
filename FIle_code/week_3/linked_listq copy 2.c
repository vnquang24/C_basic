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

Student* insertStudent(Student* head, int mssv, float diem) {
    Student* newStudent = createStudent(mssv, diem);
    if (head == NULL) {
        return newStudent;
    }
    Student* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newStudent;
    return head;
}

Student* swapNodes(Student* head, Student* currX, Student* currY, Student* prevX, Student* prevY) {
    if (currX == currY) return head;
    if (prevX != NULL) prevX->next = currY;
    else head = currY;
    if (prevY != NULL) prevY->next = currX;
    else head = currX;
    Student* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
    return head;
}

Student* sortList(Student* head) {
    Student *prevX = NULL, *currX = head;
    while (currX != NULL) {
        Student *prevY = NULL, *currY = head;
        while (currY != NULL) {
            if (currX->diem < currY->diem) {
                head = swapNodes(head, currX, currY, prevX, prevY);
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
    return head;
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
        head = insertStudent(head, mssv, diem);
    }
    head = sortList(head);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    printList(head);
    return 0;
}