// 0x80134BF0 (84 bytes)
// RelMatrixImpl::GetArraySize(int)

class RelMatrixImpl { public: void GetArraySize(int); };

__attribute__((naked))
void RelMatrixImpl::GetArraySize(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x48000389\n.long 0x801E0008\n.long 0x7C030000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000018\n.long 0x81230000\n.long 0x80090000\n.long 0x80690004\n.long 0x7C601850\n.long 0x7C631670\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
