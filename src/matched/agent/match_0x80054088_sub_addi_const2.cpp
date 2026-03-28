/* 36-byte wrapper at 0x80054088: constant 2 */

extern void target_80054088(void*, int);

void sub_80054088(void *self) {
    target_80054088(self, 2);
}
