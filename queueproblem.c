// queueproblem.c - Lab 02 - Ewen, Crawford

#include <stdlib.h>
#include <stdio.h>

// Print line width
#define width 12

struct Item {
    struct Item* next;
    int value;
};
typedef struct Item Item, *pItem;

struct Queue {
    Item* front;
    Item* back;
};
typedef struct Queue Queue, *pQueue;

void insert(Queue* queue, int val) {
    // Create and initialize new queue item
    Item* newItem = malloc(sizeof(newItem));
    if (newItem == NULL) {return;}
    newItem->next = NULL;
    newItem->value = val;
    // Add new item to queue
    if (queue->front == NULL) { // If first item in queue
        queue->front = newItem;
    }
    // Otherwise, if queue already has items, point last item's next pointer to
    // new item
    else {
        queue->back->next = newItem;
    }
    // Set last item in queue to new item
    queue->back = newItem;
}

void print(Queue* queue) {
    if (queue->front == NULL) {return;}
    int w = 0;
    Item* item = queue->front;
    while (item != NULL) {
        if (w == width) {
            w = 0;
            printf("\n");
        }
        printf("%5d", item->value);
        w++;
        item = item->next;
    }
    printf("\n");
}

int main(void) {
    // Queues
    Queue q1 = {.front = NULL, .back = NULL};
    Queue q2 = {.front = NULL, .back = NULL};
    Queue q3 = {.front = NULL, .back = NULL};
    Queue q4 = {.front = NULL, .back = NULL};
    // Read input
    int input;
    while (1) {
        scanf("%i", &input);
        // When input is negative, print contents of each queue and stop loop
        if (input < 0) {
            print(&q1);
            print(&q2);
            print(&q3);
            print(&q4);
            break;
        }
        // For all non-negative input values, insert into appropriate queue
        switch (input % 4) {
            case 0:
                insert(&q1, input);
                break;
            case 1:
                insert(&q2, input);
                break;
            case 2:
                insert(&q3, input);
                break;
            case 3:
                insert(&q4, input);
                break;
        }
    }
    
    return 0;
}