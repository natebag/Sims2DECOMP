/* 44-byte wrapper at 0x8001EAE4: calls with constants (1, 0xFFFF) */

extern void target_8001EAE4(int, unsigned int);

void sub_8001EAE4(void) {
    target_8001EAE4(1, 0xFFFF);
}
