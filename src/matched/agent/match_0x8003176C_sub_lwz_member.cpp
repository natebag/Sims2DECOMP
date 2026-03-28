/* 36-byte wrapper at 0x8003176C: loads member at +1596 and calls */

struct W_8003176C { char pad[1596]; void *field; };
extern void target_8003176C(void*);

void sub_8003176C(W_8003176C *self) {
    target_8003176C(self->field);
}
