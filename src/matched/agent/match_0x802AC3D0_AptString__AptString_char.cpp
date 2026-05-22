// 0x802AC3D0 AptString::AptString(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 4,1; bl _s802AC3D0_0; lis 9,-32703; addi 3,30,12; addi 9,9,2048; mr 4,29; stw 9,0x8(30); bl _s802AC3D0_1; li 0,0; mr 3,30; stw 0,0x10(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802AC3D0_0();
extern "C" void _s802AC3D0_1();
extern "C" void f_802AC3D0() {}
