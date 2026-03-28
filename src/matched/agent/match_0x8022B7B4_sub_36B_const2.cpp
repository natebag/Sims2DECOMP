/* 36-byte wrapper at 0x8022B7B4: passes this + constant 2 */

extern void target_8022B7D8(void*, int);

void sub_8022B7B4(void *self) {
    target_8022B7D8(self, 2);
}
