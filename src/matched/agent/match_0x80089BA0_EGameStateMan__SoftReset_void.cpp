// 0x80089BA0 EGameStateMan::SoftReset(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); cmpwi 3,0; beq 0f; lwz 3,0x0(3); li 4,0; lwz 9,0x8(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 0:; lis 30,-32697; li 0,0; addi 3,30,24012; stw 0,0x0(31); bl _s80089BA0_0; addi 3,30,24012; bl _s80089BA0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80089BA0_0();
extern "C" void _s80089BA0_1();
extern "C" void f_80089BA0() {}
