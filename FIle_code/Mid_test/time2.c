#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {
    int year, month, day, hour, minute, second;
    char user_id[50];
    char question_id[50];
    struct Event* next;
} Event;

Event* create_event(int year, int month, int day, int hour, int minute, int second, char* user_id, char* question_id) {
    Event* event = (Event*)malloc(sizeof(Event));
    event->year = year;
    event->month = month;
    event->day = day;
    event->hour = hour;
    event->minute = minute;
    event->second = second;
    strcpy(event->user_id, user_id);
    strcpy(event->question_id, question_id);
    event->next = NULL;
    return event;
}

Event* add_event(Event* head, int year, int month, int day, int hour, int minute, int second, char* user_id, char* question_id) {
    Event* new_event = create_event(year, month, day, hour, minute, second, user_id, question_id);
    new_event->next = head;
    return new_event;
}
int convert_to_seconds(Event* event) {
    int seconds = event->second;
    seconds += event->minute * 60;
    seconds += event->hour * 60 * 60;
    seconds += event->day * 24 * 60 * 60;
    // Assume each month has 30 days
    seconds += event->month * 30 * 24 * 60 * 60;
    // Assume each year has 365 days
    seconds += event->year * 365 * 24 * 60 * 60;
    return seconds;
}

void print_time_difference(Event* first, Event* last) {
    int diff = convert_to_seconds(last) - convert_to_seconds(first);
    int days = diff / (24 * 60 * 60);
    diff = diff % (24 * 60 * 60);
    int hours = diff / (60 * 60);
    diff = diff % (60 * 60);
    int minutes = diff / 60;
    int seconds = diff % 60;

    printf("Time difference: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
}
int main() {
    Event* head = NULL;
    char date[11], time[9], user_id[50], question_id[50];

    while (1) {
        scanf("%s", date);
        if (strcmp(date, "*") == 0) break;
        scanf("%s %s %s", time, user_id, question_id);
        int year, month, day, hour, minute, second;
        sscanf(date, "%d-%d-%d", &year, &month, &day);
        sscanf(time, "%d:%d:%d", &hour, &minute, &second);
        head = add_event(head, year, month, day, hour, minute, second, user_id, question_id);
    }

    if (head != NULL && head->next != NULL) {
        Event* first = head;
        while (head->next != NULL) {
            head = head->next;
        }
        Event* last = head;

        printf("Time difference: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);

    }

    return 0;
}