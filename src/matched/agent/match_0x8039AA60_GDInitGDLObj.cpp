// 0x8039AA60 GDInitGDLObj (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3); add 0,4,5; stw 4,0x8(3); stw 0,0xc(3); stw 5,0x4(3)"
extern "C" void f_8039AA60() {}
