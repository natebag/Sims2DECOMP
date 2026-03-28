/* 36-byte wrapper at 0x8022AFD4: passes this + constant 2 */

extern void target_8022AFF8(void*, int);

void sub_8022AFD4(void *self) {
    target_8022AFF8(self, 2);
}
