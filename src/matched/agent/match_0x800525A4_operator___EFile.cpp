// 0x800525A4 operator>>(EFile (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; addi 4,1,8; bl _s800525A4_0; lwz 0,0x8(1); mr 3,30; stw 0,0x0(29); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800525A4_0();
extern "C" void f_800525A4() {}
