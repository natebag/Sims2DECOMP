// TArray<SimsLightInfo, TArrayERModelAllocator>::Copy(SimsLightInfo*, SimsLightInfo*, int) @ 0x803C5198 (92B)
// Copies count 28-byte SimsLightInfo structs from src to dst.
// Compiler uses r5 as counter; DOL uses r8. Swap preamble cmpwi/addi + relabel r5→r8 in loop.
// Step 1: nop preamble addi 5,5,-1 (placeholder)
// ASMPROC_replace_insn: match="addi 5,5,-1" replacement="nop"
// Step 2: preamble cmpwi → addi r8,r5,-1
// ASMPROC_replace_insn: match="cmpwi 0,5,0" replacement="addi 8,5,-1"
// Step 3: loop cmpwi r5 → cmpwi r8
// ASMPROC_replace_insn: match="cmpwi 0,5,0" replacement="cmpwi 0,8,0"
// Step 4: loop addi r5,r5,-1 → addi r8,r8,-1
// ASMPROC_replace_insn: match="addi 5,5,-1" replacement="addi 8,8,-1"
// Step 5: restore nop → cmpwi r5,0 (preamble check)
// ASMPROC_replace_insn: match="nop" replacement="cmpwi 0,5,0"

struct SimsLightInfo {
    int f0, f1, f2, f3, f4, f5, f6;
};

struct TArrayERModelAllocator;

template <typename T, typename A>
struct TArray_SLI {
    static void Copy(T* dst, T* src, int count);
};

template <>
void TArray_SLI<SimsLightInfo, TArrayERModelAllocator>::Copy(SimsLightInfo* dst, SimsLightInfo* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (i--);
}
