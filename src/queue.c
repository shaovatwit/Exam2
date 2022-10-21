#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main() {
    struct Queue* queue = createQueue(5); //Creates queue.
    struct PCB firstElement = head(queue); //Adds first PCB and last PCB.
    struct PCB lastElement = tail(queue);

    printf("INITIAL QUEUE, each Process ID correlates to the PCB name.\n");
    printf("PCB7-\n Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", firstElement.processID, firstElement.pid, firstElement.state, firstElement.registers, &firstElement);
    printf("PCB2-\n Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", lastElement.processID, lastElement.pid, lastElement.state, lastElement.registers, &lastElement);

    struct PCB PCB7 = dequeue(queue); //Dequeues to add the next two.
    struct PCB PCB2 = dequeue(queue);
    struct PCB PCB4 = createPCB(4, 3, 2, "READY");
    struct PCB PCB9 = createPCB(9, 8, 7, "WAITING");

    printf("QUEUE AFTER INSERTING NEW PCB 4 & 9\n");
    enqueue(queue, PCB4);
    printf("PCB4-\n Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", tail(queue).processID, tail(queue).pid, tail(queue).state, tail(queue).registers, &tail);
    enqueue(queue, PCB7);
    printf("PCB7-\n Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", tail(queue).processID, tail(queue).pid, tail(queue).state, tail(queue).registers, &tail);
    enqueue(queue, PCB2);
    printf("PCB2-\n Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", tail(queue).processID, tail(queue).pid, tail(queue).state, tail(queue).registers, &tail);
    enqueue(queue, PCB9);
    printf("Process ID: %i\n PID: %i\n State: %s\n Registers: %i\n Memory: %p\n", tail(queue).processID, tail(queue).pid, tail(queue).state, tail(queue).registers, &tail);

    free(queue);

    return 0;
}

struct PCB createPCB(int processID, int PID, int registers, char* state) { //Creation of PCB
    struct PCB pcb = {.processID = processID, .pid = PID, .registers = registers, .state = state};
    return pcb;
}

struct Queue* createQueue(unsigned capacity) { //Creation of a queue with the two PCB's
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->head = queue->size = 0;
    queue->tail = capacity-1;
    queue->array = malloc(queue->capacity * sizeof(struct PCB));
    struct PCB PCB7 = createPCB(7,6,1, "RUNNING");
    struct PCB PCB2 = createPCB(2,1,1, "READY");

    enqueue(queue, PCB7);
    enqueue(queue, PCB2);

    return queue;
}

void enqueue(struct Queue* queue, struct PCB pcb) { //Enqueueing items.
    if (isFull(queue)) return;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->array[queue->tail] = pcb;
    queue->size = queue->size+1;
}

struct PCB dequeue(struct Queue* queue) { //Dequeues items and returns the value.
    if (isEmpty(queue)) return queue->array[queue->head];
    struct PCB pcb = queue->array[queue->head];
    queue->head = (queue->head+1) % queue->capacity;
    queue->size = queue->size-1;
    return pcb;
}

int isEmpty(struct Queue* queue) { //Checks if the queue is empty
    return (queue->size == 0);
}

int isFull(struct Queue* queue) { //Checks if the queue is full
    return (queue->size == queue->capacity);
}

struct PCB head(struct Queue* queue) { //Gets the head
    if (isEmpty(queue)) return queue->array[queue->head];
    return queue->array[queue->head];
}

struct PCB tail(struct Queue* queue) { //Gets the tail
    if (isEmpty(queue)) return queue->array[queue->head];
    return queue->array[queue->tail];
}