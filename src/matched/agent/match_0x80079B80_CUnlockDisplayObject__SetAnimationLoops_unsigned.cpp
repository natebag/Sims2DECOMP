// 0x80079B80 CUnlockDisplayObject::SetAnimationLoops(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x38(3)"
extern "C" void f_80079B80() {}
