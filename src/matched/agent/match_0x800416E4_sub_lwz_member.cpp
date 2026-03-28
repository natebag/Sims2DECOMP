/* 36-byte wrapper at 0x800416E4: loads member at +268 and calls */

struct W_800416E4 { char pad[268]; void *field; };
extern void target_800416E4(void*);

void sub_800416E4(W_800416E4 *self) {
    target_800416E4(self->field);
}
