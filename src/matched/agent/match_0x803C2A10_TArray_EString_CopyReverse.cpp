// 0x803C2A10 TArray<EString, TArrayDefaultAllocator>::CopyReverse(EString*, EString*, int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="mr 29,3" replacement="mr 31,5"
// ASMPROC_replace_insn: match="mr 30,4" replacement="slwi 9,31,2"
// ASMPROC_replace_insn: match="addi 31,5,-1" replacement="cmpwi 0,31,0"
// ASMPROC_replace_insn: match="cmpwi 0,5,0" replacement="addi 9,9,-4"
// ASMPROC_replace_insn: match="bc 12,2,.L2" occurrence=0 replacement="addi 31,31,-1"
// ASMPROC_replace_insn: match="slwi 0,31,2" occurrence=0 replacement="add 29,3,9"
// ASMPROC_replace_insn: match="add 29,29,0" replacement="add 30,4,9"
// ASMPROC_replace_insn: match="add 30,30,0" replacement="bc 12,2,.L2"
// ASMPROC_insert_mr: before="lwz 4,0(30)" src=30 dst=9
// ASMPROC_swap_adj: a="lwz" b="mr" which=first
// ASMPROC_replace_insn: match="lwz 4,0(30)" replacement="lwz 4,0(9)"
// ASMPROC_swap_adj: a="addi" b="addi" which=1

struct EString { char* ptr; };
extern void EString_op_assign(EString* dst, char* src);

void TArray_EString_CopyReverse(EString* dst, EString* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    int offset = (i * 4);
    dst = (EString*)((char*)dst + offset);
    src = (EString*)((char*)src + offset);
    do {
        EString_op_assign(dst, src->ptr);
        dst--; src--;
    } while (i-- != 0);
}
