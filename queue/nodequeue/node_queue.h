#ifndef NODE_QUEUE_H
#define NODE_QUEUE_H

#include <stdlib.h> // size_t

struct queue;
struct queue* nqueue_create(void);
size_t nqueue_size(struct queue *q);
void nqueue_destroy(struct queue *q);
void *nqueue_head(struct queue *q);
void nqueue_push(struct queue *q, void *data);
void *nqueue_pop(struct queue *q);

#endif //NODE_QUEUE_H
