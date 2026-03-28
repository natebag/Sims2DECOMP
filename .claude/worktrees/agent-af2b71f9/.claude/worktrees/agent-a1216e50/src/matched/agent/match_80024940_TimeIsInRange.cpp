// 0x80024940 (76 bytes)
// TimeIsInRange(int, int, int)

__attribute__((naked))
void TimeIsInRange(int, int, int) {
    asm volatile(".long 0x7C042800\n.long 0x40810024\n.long 0x7C032000\n.long 0x38000000\n.long 0x4080000C\n.long 0x7C032800\n.long 0x41810008\n.long 0x38000001\n.long 0x7C030378\n.long 0x4E800020\n.long 0x7C032000\n.long 0x38000000\n.long 0x41800014\n.long 0x7F832800\n.long 0x4FFEE382\n.long 0x7C000026\n.long 0x540007FE\n.long 0x7C030378\n.long 0x4E800020");
}
