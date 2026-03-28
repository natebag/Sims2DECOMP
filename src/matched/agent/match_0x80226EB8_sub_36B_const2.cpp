/* 36-byte wrapper at 0x80226EB8: passes this + constant 2 */

extern void target_80226EDC(void*, int);

void sub_80226EB8(void *self) {
    target_80226EDC(self, 2);
}
