// 0x8000B1B0 AptFormat::~AptFormat(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 31,3; addi 9,9,-21064; lwz 30,0x40(31); stw 9,0x8c(31); mr 28,4; bl _s8000B1B0_0; mr 4,30; bl _s8000B1B0_1; lwz 30,0x30(31); bl _s8000B1B0_2; mr 4,30; bl _s8000B1B0_3; lwz 30,0x2c(31); bl _s8000B1B0_4; mr 4,30; bl _s8000B1B0_5; lwz 11,0x48(31); cmpwi 11,0; beq 0f; lwz 9,0x9c(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x48(31); 0:; lwz 3,0x64(31); cmpwi 3,0; beq 1f; bl _s8000B1B0_6; li 0,0; stw 0,0x64(31); 1:; lwz 9,0x50(31); cmpwi 9,0; beq 4f; lwz 0,0x4(9); cmpwi 0,0; beq 4f; mr 30,9; li 29,0; 2:; lwz 3,0x4(30); li 5,0; lwz 4,-25156(13); bl _s8000B1B0_7; lwz 3,0x4(30); bl _s8000B1B0_8; lwz 11,0x4(30); cmpwi 11,0; beq 3f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 3:; stw 29,0x4(30); lwz 30,0x0(30); cmpwi 30,0; bne 2b; 4:; lwz 0,0x4c(31); cmpwi 0,0; beq 7f; lwz 30,0x50(31); cmpwi 30,0; beq 6f; lis 29,-32692; 5:; lwz 4,0xc(30); addi 3,29,6092; bl _s8000B1B0_9; lwz 30,0x0(30); cmpwi 30,0; bne 5b; 6:; li 0,0; stw 0,0x4c(31); 7:; lwz 0,0x50(31); cmpwi 0,0; beq 9f; 8:; lwz 9,0x50(31); lwz 30,0x0(9); mr 3,9; bl _s8000B1B0_10; cmpwi 30,0; stw 30,0x50(31); bne 8b; 9:; andi. 0,28,1; beq 10f; mr 3,31; bl _s8000B1B0_11; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8000B1B0_0();
extern "C" void _s8000B1B0_1();
extern "C" void _s8000B1B0_2();
extern "C" void _s8000B1B0_3();
extern "C" void _s8000B1B0_4();
extern "C" void _s8000B1B0_5();
extern "C" void _s8000B1B0_6();
extern "C" void _s8000B1B0_7();
extern "C" void _s8000B1B0_8();
extern "C" void _s8000B1B0_9();
extern "C" void _s8000B1B0_10();
extern "C" void _s8000B1B0_11();
extern "C" void f_8000B1B0() {}
