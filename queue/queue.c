#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queue
{
	int front;
	int end;
	int size;
	int *array;
	int max_sz;

} * Queue;

//cria uma nova queue
Queue new_Queue(int size)
{
	Queue queue = malloc(sizeof(struct queue));
	queue->end = 0;
	queue->front = 0;
	queue->size = 0;
	queue->array = calloc(size, sizeof(int));
	queue->max_sz = size;
	return queue;
}

//adiciona um elemento no final da fila
void queue_enqueue(Queue queue, int value)
{

	queue->size++;

	if (queue->end < queue->max_sz)
	{
		queue->array[queue->end] = value;
		queue->end++;
	}

	else
	{
		queue->end = 0;
		queue->array[queue->end] = value;
	}
}

//retorna o primeiro elemento da fila
int queue_front(Queue queue)
{
	return queue->array[queue->front];
}

//remove o último elemento e retorna-o
int queue_dequeue(Queue queue)
{
	if (queue->size != 0)
	{
		queue->size--;
		int tmp = queue->array[queue->front];

		queue->array[queue->front] = INT32_MIN;

		if (queue->front < queue->max_sz)
			queue->front++;
		else
			queue->front = 0;

		return tmp;
	}
	return INT32_MIN;
}

//
int queue_size(Queue queue)
{
	return queue->size;
}

bool queue_isEmpty(Queue queue)
{
	return queue->size == 0;
}

int *queue_get_array(Queue queue)
{
	return queue->array;
}

void queue_print(Queue queue)
{

	printf("[");

	if (queue->size > 0)
	{
		for (int i = queue->front; i < queue->front + queue->size; i++)
			if (queue->array[i] != INT32_MIN)
				printf(" %d, ", queue->array[i]);
	}

	printf("]\n");
}

void queue_free(Queue queue)
{
	free(queue->array);
	free(queue);
}
