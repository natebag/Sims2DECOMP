// 0x8026710C AISetDSPSampleRate (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 26,0x10(1); mr 26,3; bl _s8026710C_0; cmplw 26,3; beq 0f; lis 31,-13312; lwz 0,0x6c00(31); cmplwi 26,0; rlwinm 0,0,0,26,24; stw 0,0x6c00(31); bne 0f; bl _s8026710C_1; mr 30,3; bl _s8026710C_2; lwz 0,0x6c00(31); addi 29,3,0; rlwinm 27,0,0,31,31; bl _s8026710C_3; addi 28,3,0; li 3,0; bl _s8026710C_4; li 3,0; bl _s8026710C_5; bl _s8026710C_6; mr 26,3; bl _s8026710C_7; lwz 4,0x6c00(31); rlwinm 0,28,1,0,30; addi 3,26,0; rlwinm 4,4,0,27,25; ori 4,4,32; stw 4,0x6c00(31); lwz 4,0x6c00(31); rlwinm 4,4,0,31,29; or 0,4,0; stw 0,0x6c00(31); lwz 0,0x6c00(31); rlwinm 0,0,0,0,30; or 0,0,27; stw 0,0x6c00(31); lwz 0,0x6c00(31); ori 0,0,64; stw 0,0x6c00(31); bl _s8026710C_8; mr 3,30; bl _s8026710C_9; mr 3,29; bl _s8026710C_10; 0:; lmw 26,0x10(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8026710C_0();
extern "C" void _s8026710C_1();
extern "C" void _s8026710C_2();
extern "C" void _s8026710C_3();
extern "C" void _s8026710C_4();
extern "C" void _s8026710C_5();
extern "C" void _s8026710C_6();
extern "C" void _s8026710C_7();
extern "C" void _s8026710C_8();
extern "C" void _s8026710C_9();
extern "C" void _s8026710C_10();
extern "C" void f_8026710C() {}
