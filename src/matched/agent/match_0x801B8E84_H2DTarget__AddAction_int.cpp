// 0x801B8E84 H2DTarget::AddAction(int, (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,9; cmplwi 4,1; bgt 0f; addi 9,3,180; rlwinm 0,4,2,0,29; lwzx 3,9,0; cmpwi 3,0; beq 0f; mr 9,11; bl _s801B8E84_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B8E84_0();
extern "C" void f_801B8E84() {}
