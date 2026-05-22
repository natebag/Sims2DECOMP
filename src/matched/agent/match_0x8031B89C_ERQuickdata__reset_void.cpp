// 0x8031B89C ERQuickdata::reset(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,0; beq 0f; bl _s8031B89C_0; 0:; lis 3,-32692; lwz 4,0x14(31); addi 3,3,-20832; bl _s8031B89C_1; li 0,0; stw 0,0x18(31); stw 0,0x14(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8031B89C_0();
extern "C" void _s8031B89C_1();
extern "C" void f_8031B89C() {}
