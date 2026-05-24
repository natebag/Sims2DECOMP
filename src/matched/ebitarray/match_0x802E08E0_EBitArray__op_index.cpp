// FLAGS: -fno-schedule-insns
// ASMPROC_insert_mr: before="stw 4,0(3)" src=3 dst=9 relabel=3:9 until=blr

struct EBitArray {
    void op_index();
};

void EBitArray::op_index() {
}
