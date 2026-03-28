/* 36-byte wrapper at 0x8022E00C: passes this + constant 2 */

extern void target_8022E030(void*, int);

void sub_8022E00C(void *self) {
    target_8022E030(self, 2);
}
