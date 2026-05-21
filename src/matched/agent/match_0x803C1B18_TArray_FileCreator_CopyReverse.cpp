// 0x803C1B18 TArray<EFileSystem::FileCreator, TArrayDefaultAllocator>::CopyReverse(FileCreator*, FileCreator*, int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="addi 8,5,-1" replacement="mulli 9,5,20"
// ASMPROC_replace_insn: match="bclr 12,2" replacement="addi 5,5,-1"
// ASMPROC_replace_insn: match="mulli 9,5,20" replacement="addi 9,9,-20" occurrence=1
// ASMPROC_replace_insn: match="addi 9,9,-20" replacement="add 3,3,9" occurrence=1
// ASMPROC_replace_insn: match="add 3,3,9" replacement="add 4,4,9" occurrence=1
// ASMPROC_replace_insn: match="add 4,4,9" replacement="bclr 12,2" occurrence=1
// ASMPROC_replace_insn: match="cmpwi 0,8,0" replacement="cmpwi 0,5,0"
// ASMPROC_replace_insn: match="addi 8,8,-1" replacement="addi 5,5,-1"
// ASMPROC_replace_insn: match="lwz 9,4(4)" replacement="lwz 0,8(4)"
// ASMPROC_replace_insn: match="lwz 11,8(4)" replacement="lwz 10,0(4)"
// ASMPROC_replace_insn: match="lwz 10,12(4)" replacement="lwz 11,4(4)"
// ASMPROC_replace_insn: match="lwz 0,0(4)" replacement="lwz 9,12(4)"
// ASMPROC_replace_insn: match="stw 9,4(3)" replacement="stw 10,0(3)"
// ASMPROC_replace_insn: match="stw 11,8(3)" replacement="stw 11,4(3)"
// ASMPROC_replace_insn: match="stw 10,12(3)" replacement="stw 0,8(3)"
// ASMPROC_replace_insn: match="stw 0,0(3)" replacement="stw 9,12(3)"

struct FileCreator {
    int a, b, c, d, e;
};

void TArray_FileCreator_CopyReverse(FileCreator* dst, FileCreator* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    int offset = count * sizeof(FileCreator) - sizeof(FileCreator);
    dst = (FileCreator*)((char*)dst + offset);
    src = (FileCreator*)((char*)src + offset);
    do {
        __builtin_memcpy(dst, src, sizeof(FileCreator));
        dst--;
        src--;
    } while (i-- != 0);
}
