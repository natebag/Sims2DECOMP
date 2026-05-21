// 0x803C2890 TArray<EString, TArrayDefaultAllocator>::Copy(EString*, EString*, int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_insert_mr: before="mr 3,29" src=30 dst=9
// ASMPROC_swap_adj: a="lwz" b="mr" which=first
// ASMPROC_swap_adj: a="lwz" b="mr" which=first
// ASMPROC_replace_insn: match="lwz 4,0(30)" replacement="lwz 4,0(9)"
// ASMPROC_swap_adj: a="addi" b="addi" which=first

struct EString { char* ptr; };
extern void EString_op_assign(EString* dst, char* src);

void TArray_EString_Copy(EString* dst, EString* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EString_op_assign(dst, src->ptr);
        dst++; src++;
    } while (i-- != 0);
}
