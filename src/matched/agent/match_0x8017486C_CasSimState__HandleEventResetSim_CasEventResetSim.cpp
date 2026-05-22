// 0x8017486C CasSimState::HandleEventResetSim(CasEventResetSim (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; stmw 27,0x9c(1); stw 0,0xb4(1); mr 31,3; mr 29,4; addi 30,1,72; addi 4,31,12; li 5,32; addi 3,1,8; bl _s8017486C_0; mr 27,30; mr 3,30; addi 4,31,76; li 5,32; addi 28,1,136; bl _s8017486C_1; lwz 29,0x8(29); addi 11,31,8; lwz 30,0x8c(31); addi 9,31,300; li 10,288; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); addi 4,1,8; li 5,32; addi 3,31,12; stw 0,0x0(11); bl _s8017486C_2; mr 4,27; addi 3,31,76; li 5,32; bl _s8017486C_3; lwz 3,0x0(31); cmpw 30,29; li 9,1; bne 1f; li 9,0; 1:; lis 30,-32698; li 0,6; addi 30,30,25128; mr 4,28; stw 0,0x88(1); stw 9,0x90(1); stw 30,0x8c(1); bl _s8017486C_4; stw 30,0x8c(1); mr 3,28; li 4,2; bl _s8017486C_5; lwz 0,0xb4(1); mtspr 8,0; lmw 27,0x9c(1); addi 1,1,176"
extern "C" void _s8017486C_0();
extern "C" void _s8017486C_1();
extern "C" void _s8017486C_2();
extern "C" void _s8017486C_3();
extern "C" void _s8017486C_4();
extern "C" void _s8017486C_5();
extern "C" void f_8017486C() {}
