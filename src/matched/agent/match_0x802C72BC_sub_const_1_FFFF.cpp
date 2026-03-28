/* 44-byte wrapper at 0x802C72BC: calls with constants (1, 0xFFFF) */

extern void target_802C72BC(int, unsigned int);

void sub_802C72BC(void) {
    target_802C72BC(1, 0xFFFF);
}
