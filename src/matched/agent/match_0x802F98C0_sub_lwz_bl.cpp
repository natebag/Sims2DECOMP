/* 36-byte wrapper at 0x802F98C0: dereferences self and calls */

struct Wrapper_802F98C0 {
    void *ptr;
};

extern void target_802F98C0(void*);

void sub_802F98C0(Wrapper_802F98C0 *self) {
    target_802F98C0(self->ptr);
}
