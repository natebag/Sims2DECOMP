/* 36-byte wrapper at 0x802F98E4: dereferences self and calls */

struct Wrapper_802F98E4 {
    void *ptr;
};

extern void target_802F98E4(void*);

void sub_802F98E4(Wrapper_802F98E4 *self) {
    target_802F98E4(self->ptr);
}
