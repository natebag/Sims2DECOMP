/* 36-byte wrapper at 0x80238090: passes this + constant 2 */

extern void target_802380B4(void*, int);

void sub_80238090(void *self) {
    target_802380B4(self, 2);
}
