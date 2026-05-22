// 0x8003ACA0 FlashPiMenu::BackedOutOfMenu(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8003ACA0_0; lwz 4,0x8(30); li 5,-1; bl _s8003ACA0_1; mr. 11,3; beq 0f; lwz 9,0x5c(11); li 4,0; lha 3,0xa8(9); lwz 0,0xac(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003ACA0_0();
extern "C" void _s8003ACA0_1();
extern "C" void f_8003ACA0() {}
