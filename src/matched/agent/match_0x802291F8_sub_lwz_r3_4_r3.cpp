/* 36-byte wrapper at 0x802291F8: loads member at +4 and calls */

struct Wrapper_802291F8 {
    int pad;
    void *field4;
};

extern void target_802363E0(void*);

void sub_802291F8(Wrapper_802291F8 *self) {
    target_802363E0(self->field4);
}
