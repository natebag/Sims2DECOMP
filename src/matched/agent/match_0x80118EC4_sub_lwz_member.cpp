/* 36-byte wrapper at 0x80118EC4: loads member at +4 and calls */

struct W_80118EC4 { char pad[4]; void *field; };
extern void target_80118EC4(void*);

void sub_80118EC4(W_80118EC4 *self) {
    target_80118EC4(self->field);
}
