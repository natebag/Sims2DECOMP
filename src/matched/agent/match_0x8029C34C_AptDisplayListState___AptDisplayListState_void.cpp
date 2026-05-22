// 0x8029C34C AptDisplayListState::~AptDisplayListState(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; lwz 9,0x0(31); mr 30,4; stw 0,0x4c(9); lwz 11,0x0(31); lwz 9,0x8(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; andi. 0,30,1; beq 0f; lwz 3,-23020(13); mr 4,31; li 5,4; bl _s8029C34C_0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8029C34C_0();
extern "C" void f_8029C34C() {}
