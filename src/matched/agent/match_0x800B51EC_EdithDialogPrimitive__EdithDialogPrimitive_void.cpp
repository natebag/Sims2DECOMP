// 0x800B51EC EdithDialogPrimitive::EdithDialogPrimitive(void) (660 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 31,3; li 30,0; lis 9,-32698; li 11,1; addi 9,9,30832; li 0,-1; addi 28,31,40; stw 30,0x0(31); stw 30,0x4(31); mr 3,28; stw 30,0x8(31); addi 27,31,48; stw 30,0xc(31); addi 26,31,52; stw 30,0x10(31); addi 25,31,56; stw 30,0x1c(31); lis 29,-32706; stw 30,0x20(31); stw 30,0x24(31); stw 9,0x84(31); stw 11,0x14(31); stw 0,0x18(31); bl _s800B51EC_0; addi 3,31,44; bl _s800B51EC_1; mr 3,27; bl _s800B51EC_2; mr 3,26; bl _s800B51EC_3; mr 3,25; bl _s800B51EC_4; li 0,3; addi 9,31,80; stw 0,0x4c(31); addi 11,31,96; stw 30,0x3c(31); addi 10,31,112; stw 30,0x40(31); addi 4,29,-26324; stw 30,0x44(31); mr 3,28; sth 30,0x48(31); sth 30,0x4a(31); stw 30,0x8(9); stw 30,0x50(31); stw 30,0x8(11); stw 30,0x60(31); stw 30,0x8(10); stw 30,0x70(31); bl _s800B51EC_5; addi 4,29,-26324; mr 3,27; bl _s800B51EC_6; addi 4,29,-26324; mr 3,26; bl _s800B51EC_7; addi 4,29,-26324; mr 3,25; bl _s800B51EC_8; lis 9,-32706; lis 11,-32698; addi 9,9,-26292; addi 11,11,-5112; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,24; stw 11,0x84(31); lis 9,-32710; addi 30,9,12328; stw 7,0x18(1); stw 8,0x1c(1); stw 31,0x10(1); cmpwi 31,0; beq 0f; addi 3,1,8; li 5,8; bl _s800B51EC_9; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); lis 9,-32706; addi 11,1,8; lwz 5,0x8(1); addi 9,9,-26284; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,31,80; lwz 0,0xc(11); cmpwi 31,0; lwz 7,0x0(9); lwz 8,0x4(9); mr 30,11; stw 5,0x50(31); lis 9,-32710; stw 0,0xc(10); addi 28,9,12448; stw 4,0x4(10); addi 9,1,32; stw 6,0x8(10); mfcr 29; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq 2f; mr 4,9; mr 3,30; li 5,8; bl _s800B51EC_10; b 3f; 2:; stw 31,0x8(1); 3:; stw 28,0x14(1); lis 9,-32706; lwz 6,0x8(1); addi 9,9,-26276; lwz 5,0x8(30); addi 11,31,96; lwz 10,0x4(30); addi 4,1,40; lwz 0,0xc(30); mtcrf 128,29; stw 6,0x60(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32710; stw 10,0x4(11); addi 28,9,12448; stw 5,0x8(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq 4f; mr 3,30; li 5,8; bl _s800B51EC_11; b 5f; 4:; stw 31,0x8(1); 5:; stw 28,0x14(1); addi 11,31,112; lwz 8,0x8(1); lis 9,-32706; lwz 7,0xc(30); addi 9,9,-26268; lwz 10,0x4(30); li 5,0; lwz 0,0x8(30); li 6,3; stw 8,0x70(31); mr 3,31; stw 7,0xc(11); stw 10,0x4(11); stw 0,0x8(11); stw 9,0x80(31); stw 5,0x88(31); stw 6,0x4c(31); lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"
extern "C" void _s800B51EC_0();
extern "C" void _s800B51EC_1();
extern "C" void _s800B51EC_2();
extern "C" void _s800B51EC_3();
extern "C" void _s800B51EC_4();
extern "C" void _s800B51EC_5();
extern "C" void _s800B51EC_6();
extern "C" void _s800B51EC_7();
extern "C" void _s800B51EC_8();
extern "C" void _s800B51EC_9();
extern "C" void _s800B51EC_10();
extern "C" void _s800B51EC_11();
extern "C" void f_800B51EC() {}
