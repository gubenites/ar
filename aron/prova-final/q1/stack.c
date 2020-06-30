#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int size, top;
} stack;

stack *create_stack(int n) {
	stack *q = malloc(sizeof(stack));
	q->data = malloc(n*sizeof(int));
	q->top = 0;
	q->size = n;
	return q;
}

void destroy_stack(stack *q) {
	free(q->data);
	free(q);
	q = NULL;
}

int stack_full(stack *q) {
	return q->top == q->size;
}

void stack_push(stack* q, int i) {
	if (!stack_full(q)) {
		q->data[q->top] = i;
		q->top++;
	}
}

int stack_pop(stack *q) {
	if (q->top > 0) {
		q->top--;
		int i = q->data[q->top];
		return i;
	}
	return 0;
}

int main() {
	stack *q = create_stack(4);
	stack_push(q, 10);
	stack_push(q, 20);
	stack_push(q, 30);
	stack_push(q, 40);
	stack_push(q, 50);
	for (int i = 0; i < 6; i++) {
		printf("Next: %d\n", stack_pop(q));
	}
	destroy_stack(q);
}
