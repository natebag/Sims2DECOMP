// FLAGS: -fno-schedule-insns
// ASMPROC_force_reg_at_pos: match="lwz 3,4(3)" pos=0 from_reg=3 to_reg=9
// ASMPROC_force_reg: match="addi 3,3,31" from_reg=3 to_reg=9
// ASMPROC_force_reg_at_pos: match="rlwinm 3,3,29,3,29" pos=1 from_reg=3 to_reg=9

struct EBitArray {
    void GetAllocByteCount();
};

void EBitArray::GetAllocByteCount() {
}
