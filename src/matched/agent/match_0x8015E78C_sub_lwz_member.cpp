/* 36-byte wrapper at 0x8015E78C: loads member at +4 and calls */

struct W_8015E78C { char pad[4]; void *field; };
extern void target_8015E78C(void*);

void sub_8015E78C(W_8015E78C *self) {
    target_8015E78C(self->field);
}
