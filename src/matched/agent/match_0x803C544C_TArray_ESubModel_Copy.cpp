// 0x803C544C TArray<ESubModel, TArrayERModelAllocator>::Copy(ESubModel*, ESubModel*, int) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_swap_adj: a="mr" b="addi" which=0
// ASMPROC_swap_adj: a="mr" b="addi" which=0
// ASMPROC_swap_adj: a="mr" b="cmpwi" which=0
// ASMPROC_swap_adj: a="mr" b="bc" which=0
// ASMPROC_swap_adj: a="mr" b="cmpwi" which=0
// ASMPROC_swap_adj: a="mr" b="bc" which=0
// ASMPROC_replace_insn: match="lwz 9,-8(31)" replacement="lwz 0,-8(31)"
// ASMPROC_replace_insn: match="stw 9,-8(30)" replacement="stw 0,-8(30)"
// ASMPROC_replace_insn: match="lwz 0,-4(31)" replacement="lwz 9,-4(31)"
// ASMPROC_replace_insn: match="stw 0,-4(30)" replacement="stw 9,-4(30)"

struct ESubModelShader { char pad[12]; };
struct ESubModel {
    ESubModelShader shaders;
    int field_C;
    int field_10;
    int field_14;
};

extern void ESubModelShader_op_assign(ESubModelShader* dst, ESubModelShader* src);

void TArray_ESubModel_Copy(ESubModel* dst, ESubModel* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ESubModelShader_op_assign(&dst->shaders, &src->shaders);
        dst++;
        src++;
        dst[-1].field_C = src[-1].field_C;
        dst[-1].field_10 = src[-1].field_10;
        dst[-1].field_14 = src[-1].field_14;
    } while (i-- != 0);
}
