// 0x80147164 TreeStack::TreeStack(TreeSimImpl&) (52B)
// DOL uses r9=this, r11=sub8, r10=sub16; GCC emits r11=this, r9=sub8, r10=sub16.
// gpr_relabel swap=9:11 corrects all register assignments globally.
// swap_adj hoists addi r11,r9,8 before stw r0,8(r9) to match DOL scheduling.
// inject_before inserts the naked frame prologue and epilogue (no callee-save push).
// ASMPROC_gpr_relabel: swap=9:11
// ASMPROC_swap_adj: a=stw b=addi which=first
// ASMPROC_inject_before: before="mr 9,3" lines="stwu 1,-16(1)"
// ASMPROC_inject_before: before="blr" lines="addi 1,1,16"

struct TreeSimImpl;
struct TreeStack {
    TreeStack(TreeSimImpl& sim);
};

TreeStack::TreeStack(TreeSimImpl& sim) {
    char* base = (char*)this;
    *(volatile int*)(base + 8) = 0;
    char* sub8 = base + 8;
    *(volatile int*)(sub8 + 4) = 0;
    char* sub16 = sub8 + 8;
    *(volatile int*)(sub16 + 4) = 0;
    *(volatile int*)(base + 24) = (int)(void*)&sim;
    *(volatile int*)(base + 4) = 0;
    *(volatile int*)(base + 0) = 0;
}
