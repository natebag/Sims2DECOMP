// 0x80009594 AptAuxPCEorGL_LoadAnimation(char (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 29,4; bl _s80009594_0; bl _s80009594_1; li 4,272; li 5,0; bl _s80009594_2; mr 31,3; li 4,0; li 5,272; bl _s80009594_3; mr 3,31; mr 4,28; bl _s80009594_4; li 8,0; b 1f; 0:; addi 8,8,1; 1:; cmplwi 8,47; bgt 2f; lis 9,-32697; rlwinm 11,8,5,0,26; addi 10,9,-6160; lwzx 0,10,11; cmpwi 0,0; bne 0b; add 0,11,10; li 9,1; stw 0,0x100(31); stwx 9,10,11; 2:; addi 30,31,260; cmpw 29,30; beq 4f; lwz 3,0x104(31); cmpwi 3,0; beq 3f; bl _s80009594_5; cmpwi 3,0; bne 3f; lwz 3,0x104(31); bl _s80009594_6; 3:; lwz 3,0x0(29); stw 3,0x0(30); cmpwi 3,0; beq 4f; bl _s80009594_7; 4:; mr 3,31; bl _s80009594_8; bl _s80009594_9; lis 3,-32707; mr 7,28; addi 3,3,-11112; li 4,0; li 5,0; li 6,1; crxor 6,6,6; bl _s80009594_10; lwz 3,0x0(29); cmpwi 3,0; beq 5f; bl _s80009594_11; cmpwi 3,0; bne 5f; lwz 3,0x0(29); bl _s80009594_12; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80009594_0();
extern "C" void _s80009594_1();
extern "C" void _s80009594_2();
extern "C" void _s80009594_3();
extern "C" void _s80009594_4();
extern "C" void _s80009594_5();
extern "C" void _s80009594_6();
extern "C" void _s80009594_7();
extern "C" void _s80009594_8();
extern "C" void _s80009594_9();
extern "C" void _s80009594_10();
extern "C" void _s80009594_11();
extern "C" void _s80009594_12();
extern "C" void f_80009594() {}
