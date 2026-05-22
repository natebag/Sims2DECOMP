// 0x8032B898 EPMDesc::EPMDesc(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; mr 3,4; bl _s8032B898_0; li 9,0; stw 3,0x0(30); li 0,-1; stw 9,0x10(30); stw 0,0x8(30); mr 3,30; stw 29,0xc(30); stw 9,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032B898_0();
extern "C" void f_8032B898() {}
