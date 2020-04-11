#include <stdbool.h>

#ifndef LIST_EDA2

typedef struct queue *Queue;

Queue new_Queue(int size);

int queue_front(Queue queue);

int queue_dequeue(Queue queue);

void queue_enqueue(Queue queue, int value);

int queue_size(Queue queue);

bool queue_isEmpty(Queue queue);

void queue_print(Queue queue);

void queue_free(Queue queue);

int *queue_get_array(Queue queue);

#endif
