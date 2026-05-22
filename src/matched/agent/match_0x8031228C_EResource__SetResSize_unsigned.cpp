// 0x8031228C EResource::SetResSize(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x10(3); rlwimi 0,4,8,0,23; stw 0,0x10(3)"
extern "C" void f_8031228C() {}
