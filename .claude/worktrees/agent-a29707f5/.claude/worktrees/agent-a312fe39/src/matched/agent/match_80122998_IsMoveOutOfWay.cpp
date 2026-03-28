// 0x80122998 (124 bytes)
// IsMoveOutOfWay(Interaction *)

__attribute__((naked))
void IsMoveOutOfWay(Interaction *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BF9F2C9\n.long 0x2C030000\n.long 0x38600000\n.long 0x41820048\n.long 0x7FE3FB78\n.long 0x4BF9F2B5\n.long 0x81230004\n.long 0xA8090368\n.long 0x8129036C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x4BFEDF01\n.long 0x2C0307C4\n.long 0x40820018\n.long 0x807F0014\n.long 0x68630003\n.long 0x20030000\n.long 0x7C601914\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
