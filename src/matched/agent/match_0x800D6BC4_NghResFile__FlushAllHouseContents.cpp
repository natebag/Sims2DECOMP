// 0x800D6BC4 NghResFile::FlushAllHouseContents(void) (68B)
//
// 16-iteration loop calling FlushHouseContents(i) for i in 1..16.
// DOL uses r31=this, r30=counter. GCC swaps to r30=this, r31=counter.
//
// Recipe: gpr_relabel 30:31 with skip_opcodes=stmw,lmw to preserve the
// prologue/epilogue save/restore range. The stmw/lmw save consecutive
// callee-saved registers starting at rN, so renaming the first reg
// breaks the save range.
//
// ASMPROC_gpr_relabel: swap=30:31 skip_opcodes=stmw,lmw

class NghResFile {
public:
    void FlushHouseContents(unsigned int idx);
    void FlushAllHouseContents();
};

void NghResFile::FlushAllHouseContents() {
    int i = 0;
loop:
    i++;
    FlushHouseContents(i);
    if (i <= 15) goto loop;
}
