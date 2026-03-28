/* 36-byte wrapper at 0x80088D30: loads member at +96 and calls */

struct W_80088D30 { char pad[96]; void *field; };
extern void target_80088D30(void*);

void sub_80088D30(W_80088D30 *self) {
    target_80088D30(self->field);
}
