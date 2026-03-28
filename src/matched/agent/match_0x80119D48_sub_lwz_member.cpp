/* 36-byte wrapper at 0x80119D48: dereferences self and calls */

struct W_80119D48 { void *ptr; };
extern void target_80119D48(void*);

void sub_80119D48(W_80119D48 *self) {
    target_80119D48(self->ptr);
}
