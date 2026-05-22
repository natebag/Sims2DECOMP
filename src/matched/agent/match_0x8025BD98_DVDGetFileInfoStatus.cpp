// 0x8025BD98 DVDGetFileInfoStatus(void) (32 B)
// FLAGS: -fno-schedule-insns
// Prologue: DOL has mflr;stw4;stwu — GCC has stwu;mflr;stw12
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 0,4(1)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// Epilogue: DOL has la;mtlr — GCC has mtlr;la
// ASMPROC_replace_insn: match="mtlr 0" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="mtlr 0" occurrence=1
extern "C" int DVDGetCommandBlockStatus(void*);
extern "C" int DVDGetFileInfoStatus(void* fileInfo) { return DVDGetCommandBlockStatus(fileInfo); }
