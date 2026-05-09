// TArray<EString, TArrayDefaultAllocator>::Copy(EString*, EString*, int) @ 0x803C2890 (92B)
// FLAGS: -fno-schedule-insns
// Copies count EString elements (size 4) by calling copy_fn(dst, src->m_buffer).
// r29=dst, r30=src, r31=i; r9=temp src ptr in loop body.
// DOL emits mr r9,r30 then mr r3,r29 then lwz r4,0(r9); compiled emits lwz r4,0(r30) then mr r3,r29.
// Fix: insert mr 9,30 before lwz, then swap lwz/mr positions via replace_insn.
// ASMPROC_insert_mr: before="lwz 4,0(30)" src=30 dst=9
// ASMPROC_replace_insn: match="lwz 4,0(30)" replacement="mr 3,29"
// ASMPROC_replace_insn: match="mr 3,29" replacement="lwz 4,0(9)" occurrence=1

struct EString_C {
    unsigned short* m_buffer;
};

extern "C" void EString_copy_assign(EString_C* dst, unsigned short* src_buf);

void TArray_EString_Copy(EString_C* dst, EString_C* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EString_C* s = src;
        EString_C* d = dst;
        unsigned short* buf = s->m_buffer;
        src++;
        dst++;
        EString_copy_assign(d, buf);
    } while (i--);
}
