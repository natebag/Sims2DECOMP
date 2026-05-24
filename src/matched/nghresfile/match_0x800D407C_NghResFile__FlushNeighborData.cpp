// 0x800D407C NghResFile::FlushNeighborData(void) (84B)
// ASMPROC_replace_insn: match="li 29,4" replacement="li 28,0" occurrence=0
// ASMPROC_replace_insn: match="li 28,0" replacement="li 29,4" occurrence=1
// ASMPROC_swap_operands: match="lwzx 3,9,31" pos=1,2
// ASMPROC_swap_operands: match="stwx 28,9,31" pos=1,2

struct NghResFile {
    void FlushNeighborData();
};

void NghResFile::FlushNeighborData() {
}
