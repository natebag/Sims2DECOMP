/* 36-byte wrapper at 0x8021FB80: passes this + constant 3 to target */

extern void target_8021FBA4(void*, int);

void sub_8021FB80(void *self) {
    target_8021FBA4(self, 3);
}
