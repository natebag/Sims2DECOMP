// 0x803C19A0 TArray<EFileSystem::FileCreator, TArrayDefaultAllocator>::Copy(FileCreator*, FileCreator*, int) (76 B)
// FLAGS: -fno-schedule-insns
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

void TArray_FileCreator_Copy(FileCreator* dst, FileCreator* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        __builtin_memcpy(dst, src, sizeof(FileCreator));
        src++;
        dst++;
    } while (i-- != 0);
}
