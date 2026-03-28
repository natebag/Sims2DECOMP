// 0x8038BF04 (88 bytes)
// __GXGetNumXfbLines

__attribute__((naked))
void __GXGetNumXfbLines() {
    asm volatile(".long 0x3803FFFF\n.long 0x5400402E\n.long 0x7CA02396\n.long 0x28040080\n.long 0x38A50001\n.long 0x40810030\n.long 0x28040100\n.long 0x40800028\n.long 0x48000008\n.long 0x5484F87E\n.long 0x548007FF\n.long 0x4182FFF8\n.long 0x7C032396\n.long 0x7C0021D6\n.long 0x7C001851\n.long 0x40820008\n.long 0x38A50001\n.long 0x28050400\n.long 0x40810008\n.long 0x38A00400\n.long 0x7CA32B78\n.long 0x4E800020");
}
