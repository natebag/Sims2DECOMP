// 0x800BE834 IFFResFile2::Reopen(void) (152B)
// ASMPROC_gpr_relabel: swap="29:31"
// ASMPROC_replace_insn: match="addi 4,1,16" replacement="addi 4,31,8"
// ASMPROC_swap_adj: a=addi b=lwz which=first
// ASMPROC_swap_adj: a=mr b=li which=first

struct IFFResFile2 {
    void Reopen();
};

void IFFResFile2::Reopen() {
}
