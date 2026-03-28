/* 36-byte wrapper at 0x800A65EC: dereferences self and calls */

struct W_800A65EC { void *ptr; };
extern void target_800A65EC(void*);

void sub_800A65EC(W_800A65EC *self) {
    target_800A65EC(self->ptr);
}
