// FLAGS: -fno-schedule-insns
// 0x80306A4C MemSet32 (36 B)
// rlwinm 5,5,0,0,29; add 0,3,5; cmpw 3,0; beqlr; stw 4,0(3); addi 3,3,4; cmpw 3,0; bne 0b
// Fill count bytes (aligned to 4) starting at dst with value. do-while loop.
extern "C" void MemSet32(int* dst, int value, int count) {
    count &= ~3;
    int* end = (int*)((char*)dst + count);
    if (dst == end) return;
    do {
        *dst++ = value;
    } while (dst != end);
}
