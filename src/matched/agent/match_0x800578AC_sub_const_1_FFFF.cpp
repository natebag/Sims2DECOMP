/* 44-byte wrapper at 0x800578AC: calls with constants (1, 0xFFFF) */

extern void target_800578AC(int, unsigned int);

void sub_800578AC(void) {
    target_800578AC(1, 0xFFFF);
}
