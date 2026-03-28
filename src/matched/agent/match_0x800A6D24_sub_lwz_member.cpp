/* 36-byte wrapper at 0x800A6D24: dereferences self and calls */

struct W_800A6D24 { void *ptr; };
extern void target_800A6D24(void*);

void sub_800A6D24(W_800A6D24 *self) {
    target_800A6D24(self->ptr);
}
