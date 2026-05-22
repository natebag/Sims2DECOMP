// 0x801C6BFC MMUTarget::EnterLot(int) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32697; li 0,1; addi 9,9,23428; mr 30,4; mr 3,9; stw 0,0xe4(9); stw 0,0x84(9); li 4,0; bl _s801C6BFC_0; lis 29,-32697; lis 3,-32705; li 4,0; addi 3,3,3292; lis 31,-32697; bl _s801C6BFC_1; lis 3,-32705; li 4,0; addi 3,3,11448; bl _s801C6BFC_2; lis 3,-32705; li 4,0; addi 3,3,-2032; bl _s801C6BFC_3; lis 5,-32705; addi 4,29,24012; addi 3,1,8; addi 5,5,11460; crxor 6,6,6; bl _s801C6BFC_4; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; lis 3,-32705; addi 3,3,5044; bl _s801C6BFC_5; lis 5,-32705; addi 4,31,24012; addi 3,1,12; addi 5,5,11488; crxor 6,6,6; bl _s801C6BFC_6; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; lis 3,-32705; addi 3,3,5064; bl _s801C6BFC_7; lis 5,-32705; addi 4,31,24012; addi 3,1,16; addi 5,5,11516; crxor 6,6,6; bl _s801C6BFC_8; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; lis 3,-32705; addi 3,3,5080; bl _s801C6BFC_9; lis 5,-32705; addi 4,31,24012; addi 5,5,11544; addi 3,1,20; crxor 6,6,6; bl _s801C6BFC_10; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; lis 3,-32705; addi 3,3,5100; bl _s801C6BFC_11; addi 9,29,24012; lbz 4,0x384(9); addi 0,4,-1; cmplwi 0,15; bgt 4f; rlwinm 30,4,0,24,31; 4:; lis 3,-32697; mr 4,30; addi 3,3,-7672; bl _s801C6BFC_12; lis 3,-32705; addi 3,3,11572; bl _s801C6BFC_13; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801C6BFC_0();
extern "C" void _s801C6BFC_1();
extern "C" void _s801C6BFC_2();
extern "C" void _s801C6BFC_3();
extern "C" void _s801C6BFC_4();
extern "C" void _s801C6BFC_5();
extern "C" void _s801C6BFC_6();
extern "C" void _s801C6BFC_7();
extern "C" void _s801C6BFC_8();
extern "C" void _s801C6BFC_9();
extern "C" void _s801C6BFC_10();
extern "C" void _s801C6BFC_11();
extern "C" void _s801C6BFC_12();
extern "C" void _s801C6BFC_13();
extern "C" void f_801C6BFC() {}
