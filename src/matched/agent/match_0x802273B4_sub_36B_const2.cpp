/* 36-byte wrapper at 0x802273B4: passes this + constant 2 */

extern void target_802273D8(void*, int);

void sub_802273B4(void *self) {
    target_802273D8(self, 2);
}
