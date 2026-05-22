// 0x8017E138 UIReflow::OpenTweenBlock(char (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 25,0x8c(1); stw 0,0xac(1); mr 31,3; mr 29,4; lwz 30,0x0(31); mr 28,5; mr 25,6; mr 26,7; mr 27,8; cmpwi 30,0; bne 4f; li 0,1; li 9,4096; stw 0,0x8(31); stw 9,0xc(31); bl _s8017E138_0; lwz 4,0xc(31); li 5,0; bl _s8017E138_1; stw 30,0x10(31); cmpwi 3,0; stw 3,0x0(31); stw 3,0x4(31); beq 4f; lis 4,-32706; mr 3,31; addi 4,4,14440; bl _s8017E138_2; lis 4,-32706; mr 3,31; addi 4,4,14184; bl _s8017E138_3; lbz 9,0x0(29); addi 9,9,-48; cmplwi 9,1; ble 1f; cmpwi 27,0; beq 0f; lis 4,-32706; mr 3,31; addi 4,4,14192; bl _s8017E138_4; b 1f; 0:; lis 4,-32706; mr 3,31; addi 4,4,14196; bl _s8017E138_5; 1:; mr 4,29; mr 3,31; bl _s8017E138_6; lis 30,-32706; lis 4,-32706; mr 3,31; addi 4,4,14200; bl _s8017E138_7; lis 4,-32706; mr 3,31; addi 4,4,14448; bl _s8017E138_8; addi 3,1,8; mr 5,28; addi 4,30,14212; crxor 6,6,6; bl _s8017E138_9; addi 4,1,8; mr 3,31; bl _s8017E138_10; lis 4,-32706; mr 3,31; addi 4,4,14456; bl _s8017E138_11; lis 4,-32706; mr 3,31; addi 4,4,14464; bl _s8017E138_12; mr 5,25; addi 3,1,8; addi 4,30,14212; crxor 6,6,6; bl _s8017E138_13; addi 4,1,8; mr 3,31; bl _s8017E138_14; lis 4,-32706; mr 3,31; addi 4,4,14476; bl _s8017E138_15; lis 4,-32706; mr 3,31; addi 4,4,14488; bl _s8017E138_16; lbz 9,0x0(26); addi 9,9,-48; cmplwi 9,1; ble 3f; cmpwi 27,0; beq 2f; lis 4,-32706; mr 3,31; addi 4,4,14192; bl _s8017E138_17; b 3f; 2:; lis 4,-32706; mr 3,31; addi 4,4,14196; bl _s8017E138_18; 3:; mr 4,26; mr 3,31; bl _s8017E138_19; lis 4,-32706; mr 3,31; addi 4,4,14496; bl _s8017E138_20; 4:; lwz 0,0xac(1); mtspr 8,0; lmw 25,0x8c(1); addi 1,1,168"
extern "C" void _s8017E138_0();
extern "C" void _s8017E138_1();
extern "C" void _s8017E138_2();
extern "C" void _s8017E138_3();
extern "C" void _s8017E138_4();
extern "C" void _s8017E138_5();
extern "C" void _s8017E138_6();
extern "C" void _s8017E138_7();
extern "C" void _s8017E138_8();
extern "C" void _s8017E138_9();
extern "C" void _s8017E138_10();
extern "C" void _s8017E138_11();
extern "C" void _s8017E138_12();
extern "C" void _s8017E138_13();
extern "C" void _s8017E138_14();
extern "C" void _s8017E138_15();
extern "C" void _s8017E138_16();
extern "C" void _s8017E138_17();
extern "C" void _s8017E138_18();
extern "C" void _s8017E138_19();
extern "C" void _s8017E138_20();
extern "C" void f_8017E138() {}
