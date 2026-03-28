/* 36-byte wrapper at 0x80088E7C: loads member at +100 and calls */

struct W_80088E7C { char pad[100]; void *field; };
extern void target_80088E7C(void*);

void sub_80088E7C(W_80088E7C *self) {
    target_80088E7C(self->field);
}
