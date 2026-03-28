/* 36-byte wrapper at 0x80041694: loads member at +268 and calls */

struct W_80041694 { char pad[268]; void *field; };
extern void target_80041694(void*);

void sub_80041694(W_80041694 *self) {
    target_80041694(self->field);
}
