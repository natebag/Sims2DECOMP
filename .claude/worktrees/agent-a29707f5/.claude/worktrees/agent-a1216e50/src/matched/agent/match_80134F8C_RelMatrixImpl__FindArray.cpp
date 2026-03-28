// 0x80134F8C (64 bytes)
// RelMatrixImpl::FindArray(int)

class RelMatrixImpl { public: void FindArray(int); };

__attribute__((naked))
void RelMatrixImpl::FindArray(int) {
    asm volatile(".long 0x81630008\n.long 0x80630004\n.long 0x7C035800\n.long 0x4D820020\n.long 0x81230000\n.long 0x80090010\n.long 0x7C002000\n.long 0x4D820020\n.long 0x38630004\n.long 0x7C035800\n.long 0x4D820020\n.long 0x81230000\n.long 0x80090010\n.long 0x7C002000\n.long 0x4082FFE8\n.long 0x4E800020");
}
