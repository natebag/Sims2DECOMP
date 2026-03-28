/* 36-byte wrapper at 0x802F9ABC: dereferences self and calls */

struct Wrapper_802F9ABC {
    void *ptr;
};

extern void target_802F9ABC(void*);

void sub_802F9ABC(Wrapper_802F9ABC *self) {
    target_802F9ABC(self->ptr);
}
