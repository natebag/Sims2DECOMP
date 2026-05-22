// 0x80359FA4 EAllocGroup::MoveContents(EAllocGroup (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80359FA4_0; lwz 9,0x14(29); mr 3,30; mr 4,29; stw 9,0x14(30); lwz 0,0x10(29); add 9,0,0; stw 0,0x10(30); stw 9,0x14(29); bl _s80359FA4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80359FA4_0();
extern "C" void _s80359FA4_1();
extern "C" void f_80359FA4() {}
