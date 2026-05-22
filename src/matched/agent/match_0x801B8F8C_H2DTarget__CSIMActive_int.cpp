// 0x801B8F8C H2DTarget::CSIMActive(int, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); rlwinm 4,4,2,0,29; addi 3,3,136; lwzx 3,3,4; cmpwi 3,0; beq 1f; cmpwi 5,0; beq 0f; li 4,1; bl _s801B8F8C_0; b 1f; 0:; li 4,4; bl _s801B8F8C_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B8F8C_0();
extern "C" void _s801B8F8C_1();
extern "C" void f_801B8F8C() {}
