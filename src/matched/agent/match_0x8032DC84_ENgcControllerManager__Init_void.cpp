// 0x8032DC84 ENgcControllerManager::Init(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); bl _s8032DC84_0; li 27,0; lis 3,-32768; lis 25,-32693; bl _s8032DC84_1; li 28,0; lis 3,16384; bl _s8032DC84_2; lis 3,8192; bl _s8032DC84_3; lis 3,4096; bl _s8032DC84_4; lis 11,-32697; lis 9,-32688; addi 9,9,-12424; addi 26,11,-15584; lis 11,-32693; stw 9,-26528(13); addi 31,11,24504; 0:; lwz 29,-26528(13); li 3,528; bl _s8032DC84_5; mr 30,3; bl _s8032DC84_6; stw 26,0x208(30); addi 4,25,-11760; stwx 30,28,29; lwz 9,-26528(13); lwz 10,-26532(13); lwzx 11,28,9; addi 28,28,4; stw 27,0x20c(11); addi 27,27,1; lwz 9,0x0(10); lha 3,0x28(9); lwz 0,0x2c(9); add 3,10,3; mtspr 8,0; blrl; stfs f1,0x0(31); cmpwi 27,3; stfs f1,0x4(31); addi 31,31,8; ble 0b; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8032DC84_0();
extern "C" void _s8032DC84_1();
extern "C" void _s8032DC84_2();
extern "C" void _s8032DC84_3();
extern "C" void _s8032DC84_4();
extern "C" void _s8032DC84_5();
extern "C" void _s8032DC84_6();
extern "C" void f_8032DC84() {}
