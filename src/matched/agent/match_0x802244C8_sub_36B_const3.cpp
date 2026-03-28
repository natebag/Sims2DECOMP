/* 36-byte wrapper at 0x802244C8: passes this + constant 3 */

extern void target_802244EC(void*, int);

void sub_802244C8(void *self) {
    target_802244EC(self, 3);
}
