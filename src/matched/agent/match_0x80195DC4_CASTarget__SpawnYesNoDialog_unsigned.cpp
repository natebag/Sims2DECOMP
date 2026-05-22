// 0x80195DC4 CASTarget::SpawnYesNoDialog(unsigned (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 25,0x3c(1); stw 0,0x5c(1); mr 31,3; mr 25,4; mr 27,5; mr 26,6; mr 28,7; li 4,0; lis 29,-32697; bl _s80195DC4_0; addi 30,31,5068; li 9,2; li 0,1; lis 5,-32705; stw 9,0x139c(31); addi 4,29,24012; stw 0,0x13a8(31); addi 5,5,-15308; addi 3,1,24; crxor 6,6,6; bl _s80195DC4_1; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s80195DC4_2; addi 30,31,5072; lis 5,-32705; addi 4,29,24012; addi 5,5,-15304; addi 3,1,28; crxor 6,6,6; bl _s80195DC4_3; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s80195DC4_4; cmpwi 31,0; stw 28,0x13a0(31); mfcr 29; mr 4,27; addi 3,31,5060; bl _s80195DC4_5; mr 4,26; addi 3,31,5064; bl _s80195DC4_6; lis 9,-32705; li 0,0; addi 9,9,-15300; stw 0,0x13bc(31); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; addi 4,1,32; addi 30,11,14432; stw 7,0x20(1); stw 8,0x24(1); mtcrf 128,29; stw 31,0x10(1); beq 2f; addi 3,1,8; li 5,8; bl _s80195DC4_7; b 3f; 2:; stw 31,0x8(1); 3:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,-15292; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,5100; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); mtcrf 128,29; stw 4,0x13ec(31); lis 9,-32709; stw 0,0xc(10); addi 28,9,14192; stw 5,0x4(10); addi 9,1,40; stw 6,0x8(10); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq 4f; mr 4,9; mr 3,30; li 5,8; bl _s80195DC4_8; b 5f; 4:; stw 31,0x8(1); 5:; stw 28,0x14(1); lis 9,-32705; lwz 5,0x8(1); addi 9,9,-15284; lwz 4,0x8(30); addi 11,31,5116; lwz 6,0x4(30); addi 0,31,5020; lwz 10,0xc(30); mr 29,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 5,0x13fc(31); lis 9,-32709; stw 10,0xc(11); addi 28,9,14552; stw 6,0x4(11); addi 9,1,48; stw 4,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 0,0x10(1); beq 6f; mr 4,9; mr 3,30; li 5,8; bl _s80195DC4_9; b 7f; 6:; stw 29,0x8(1); 7:; stw 28,0x14(1); addi 9,31,5132; lwz 0,0x8(1); lwz 11,0xc(30); lwz 10,0x4(30); lwz 8,0x8(30); stw 0,0x140c(31); stw 11,0xc(9); stw 10,0x4(9); stw 8,0x8(9); lwz 0,0x1360(31); cmpwi 0,0; bne 8f; li 0,1; b 9f; 8:; cmpwi 0,1; bne 10f; li 0,2; 9:; stw 0,0x13e8(31); 10:; stw 25,0x1424(31); mr 3,29; bl _s80195DC4_10; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x3c(1); addi 1,1,88"
extern "C" void _s80195DC4_0();
extern "C" void _s80195DC4_1();
extern "C" void _s80195DC4_2();
extern "C" void _s80195DC4_3();
extern "C" void _s80195DC4_4();
extern "C" void _s80195DC4_5();
extern "C" void _s80195DC4_6();
extern "C" void _s80195DC4_7();
extern "C" void _s80195DC4_8();
extern "C" void _s80195DC4_9();
extern "C" void _s80195DC4_10();
extern "C" void f_80195DC4() {}
