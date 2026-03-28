/* 36-byte wrapper at 0x8012FDAC: dereferences self and calls */

struct W_8012FDAC { void *ptr; };
extern void target_8012FDAC(void*);

void sub_8012FDAC(W_8012FDAC *self) {
    target_8012FDAC(self->ptr);
}
