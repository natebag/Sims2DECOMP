// 0x80268C48 AptReset(void) (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32694; li 0,1; stw 0,-15940(9); bl _s80268C48_0; lwz 3,-23008(13); bl _s80268C48_1; li 3,1; bl _s80268C48_2; lwz 3,-23000(13); cmpwi 3,0; beq 0f; li 4,3; bl _s80268C48_3; 0:; lwz 3,-22996(13); cmpwi 3,0; beq 1f; li 4,3; bl _s80268C48_4; 1:; lwz 3,-22992(13); cmpwi 3,0; beq 2f; li 4,3; bl _s80268C48_5; 2:; li 3,1; li 29,0; bl _s80268C48_6; bl _s80268C48_7; bl _s80268C48_8; bl _s80268C48_9; lwz 3,-27600(13); bl _s80268C48_10; lwz 3,-23020(13); li 4,4; lwz 30,-23008(13); bl _s80268C48_11; bl _s80268C48_12; stw 3,0x28(30); bl _s80268C48_13; lis 3,-32694; addi 3,3,-16116; bl _s80268C48_14; lwz 3,-23020(13); li 4,4; bl _s80268C48_15; mr 9,3; li 4,24; stw 29,0x0(9); lwz 3,-23020(13); stw 9,-23000(13); bl _s80268C48_16; mr 10,3; li 8,0; addi 9,10,4; stw 29,0x0(10); stw 29,0x4(10); addi 0,10,16; stw 29,0x4(9); mr 11,0; stw 0,0x8(9); li 9,1; 3:; stw 8,0x0(11); cmpwi 9,0; addi 11,11,4; addi 9,9,-1; bne 3b; lwz 3,-23020(13); li 4,28; stw 10,-22996(13); li 31,1; bl _s80268C48_17; li 28,0; mr 29,3; li 0,0; addi 9,29,12; stw 0,0x4(29); stw 0,0x0(29); mr 30,9; stw 9,0x8(29); 4:; mr 3,30; bl _s80268C48_18; stw 28,0x4(30); cmpwi 31,0; addi 30,30,8; addi 31,31,-1; bne 4b; lwz 3,-23008(13); stw 29,-22992(13); bl _s80268C48_19; lis 9,-32694; li 0,0; stw 0,-15940(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80268C48_0();
extern "C" void _s80268C48_1();
extern "C" void _s80268C48_2();
extern "C" void _s80268C48_3();
extern "C" void _s80268C48_4();
extern "C" void _s80268C48_5();
extern "C" void _s80268C48_6();
extern "C" void _s80268C48_7();
extern "C" void _s80268C48_8();
extern "C" void _s80268C48_9();
extern "C" void _s80268C48_10();
extern "C" void _s80268C48_11();
extern "C" void _s80268C48_12();
extern "C" void _s80268C48_13();
extern "C" void _s80268C48_14();
extern "C" void _s80268C48_15();
extern "C" void _s80268C48_16();
extern "C" void _s80268C48_17();
extern "C" void _s80268C48_18();
extern "C" void _s80268C48_19();
extern "C" void f_80268C48() {}
