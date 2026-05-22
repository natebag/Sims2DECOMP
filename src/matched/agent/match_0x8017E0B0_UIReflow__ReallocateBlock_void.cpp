// 0x8017E0B0 UIReflow::ReallocateBlock(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 0f; lwz 9,0x8(31); addi 9,9,1; rlwinm 0,9,12,0,19; stw 9,0x8(31); stw 0,0xc(31); bl _s8017E0B0_0; lwz 4,0xc(31); li 5,0; bl _s8017E0B0_1; mr 30,3; lwz 4,0x0(31); bl _s8017E0B0_2; bl _s8017E0B0_3; lwz 4,0x0(31); bl _s8017E0B0_4; stw 30,0x0(31); mr 3,30; bl _s8017E0B0_5; lwz 0,0x0(31); add 0,0,3; stw 0,0x4(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8017E0B0_0();
extern "C" void _s8017E0B0_1();
extern "C" void _s8017E0B0_2();
extern "C" void _s8017E0B0_3();
extern "C" void _s8017E0B0_4();
extern "C" void _s8017E0B0_5();
extern "C" void f_8017E0B0() {}
