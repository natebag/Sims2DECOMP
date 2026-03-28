// 0x80142484 (124 bytes)
// GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&)

__attribute__((naked))
void GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x81230004\n.long 0x7CBD2B78\n.long 0x7C9E2378\n.long 0xA80901F8\n.long 0x812901FC\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x800D8454\n.long 0x5463103A\n.long 0x7FC4F378\n.long 0x7C630214\n.long 0x81630010\n.long 0x812B0000\n.long 0xA8690020\n.long 0x80090024\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x907D0000\n.long 0x38600000\n.long 0x38800001\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
