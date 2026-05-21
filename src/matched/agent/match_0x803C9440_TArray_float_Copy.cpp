// 0x803C9440 TArray<float, TArrayERAnimAllocator>::Copy(float*, float*, int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="addi 0,5,-1" replacement="addi 9,5,-1"
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,9,0"
// ASMPROC_replace_insn: match="addic 0,0,-1" replacement="addi 9,9,-1"

void TArray_float_Copy(float* dst, float* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
