// 0x801B8E3C H2DTarget::NewWantFearIcon(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); rlwinm 4,4,2,0,29; addi 3,3,172; lwzx 3,3,4; mr 4,5; mr 5,6; cmpwi 3,0; mr 6,7; mr 7,8; mr 8,9; beq 0f; bl _s801B8E3C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B8E3C_0();
extern "C" void f_801B8E3C() {}
