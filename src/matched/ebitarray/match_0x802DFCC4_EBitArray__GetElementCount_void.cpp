// 0x802DFCC4 EBitArray::GetElementCount(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3); addi 3,3,31; rlwinm 3,3,27,5,31"

struct EBitArray {
    void GetElementCount();
};

void EBitArray::GetElementCount() {
}
