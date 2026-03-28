/* 36-byte wrapper at 0x80118EE8: loads member at +4 and calls */

struct W_80118EE8 { char pad[4]; void *field; };
extern void target_80118EE8(void*);

void sub_80118EE8(W_80118EE8 *self) {
    target_80118EE8(self->field);
}
