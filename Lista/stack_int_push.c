void stack_int_push(stack_int *s, int value, int index) {
    int i;
    for (i = s->size; i > index; i--) {
        s->data[i] = s->data[i-1];
    }
    s->data[i] = value;
    s->size++;
}
