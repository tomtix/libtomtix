#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct stack;

struct stack *stack_create(size_t buf_size);
void stack_destroy(struct stack *stack);

void stack_push(struct stack *s, int element);
int stack_pop(struct stack *s);
int stack_top(const struct stack *s);
int stack_is_empty(const struct stack *s);
int stack_is_full(const struct stack *s);
size_t stack_size(const struct stack *s);

#endif //STACK_H