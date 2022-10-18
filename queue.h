//
// Created by shaov on 10/17/2022.
//

#include <malloc.h>

#ifndef EXAM2_QUEUE_H
#define EXAM2_QUEUE_H
struct PCB {
    int processID, pid, registers;
    char* state;
};

struct Queue {
    int head, tail, size;
    struct PCB* array;
    unsigned capacity;
};

struct PCB createPCB(int processID, int PID, int registers, char* state);

struct Queue* createQueue(unsigned capacity);

void enqueue(struct Queue* queue, struct PCB pcb);

struct PCB dequeue(struct Queue* queue);

void insertHead(struct Queue* queue, struct PCB pcb);

int isEmpty(struct Queue* queue);

int isFull(struct Queue* queue);

struct PCB head(struct Queue* queue);

struct PCB tail(struct Queue* queue);
#endif //EXAM2_QUEUE_H