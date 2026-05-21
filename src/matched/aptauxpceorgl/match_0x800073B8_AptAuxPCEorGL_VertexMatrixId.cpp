// 0x800073B8 (40 bytes) AptAuxPCEorGL_VertexMatrixId(void)
// ASMPROC_replace_insn: match="ori 3,3,59312" replacement="addi 3,3,59312"
struct EMat4 {
    void Id();
};

void AptAuxPCEorGL_VertexMatrixId() {
    EMat4* m = (EMat4*)0x8047E7B0;
    m->Id();
}
