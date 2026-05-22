// 0x800310EC ESim::~ESim(void) (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; lis 11,-32698; mr 31,3; addi 9,9,-19760; addi 11,11,-19704; mr 29,4; stw 9,0x320(31); stw 11,0x0(31); bl _s800310EC_0; cmpwi 3,0; beq 0f; lis 3,-32697; addi 3,3,14696; bl _s800310EC_1; 0:; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; bl _s800310EC_2; lwz 11,0x628(31); cmpwi 11,0; beq 1f; lwz 9,0x3b0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; li 30,0; mr 3,31; stw 30,0x628(31); bl _s800310EC_3; lwz 3,0x3e8(31); cmpwi 3,0; beq 2f; bl _s800310EC_4; stw 30,0x3e8(31); 2:; lwz 3,0x42c(31); cmpwi 3,0; beq 3f; bl _s800310EC_5; stw 30,0x42c(31); 3:; lwz 11,0x3e0(31); stw 30,0x42c(31); cmpwi 11,0; beq 6f; lwz 9,0x0(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 3,0x3e0(31); lwz 9,0x0(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; lwz 4,0x3e0(31); bl _s800310EC_6; 4:; lwz 11,0x3e0(31); cmpwi 11,0; beq 5f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 5:; stw 30,0x3e0(31); 6:; lwz 3,0x408(31); cmpwi 3,0; beq 7f; bl _s800310EC_7; li 0,0; stw 0,0x408(31); 7:; lwz 3,0x40c(31); cmpwi 3,0; beq 8f; bl _s800310EC_8; li 0,0; stw 0,0x40c(31); 8:; lwz 3,0x410(31); cmpwi 3,0; beq 9f; bl _s800310EC_9; li 0,0; stw 0,0x410(31); 9:; lwz 0,-32584(13); cmpw 0,31; bne 10f; li 0,0; stw 0,-32584(13); 10:; mr 3,31; li 4,0; bl _s800310EC_10; andi. 0,29,1; beq 11f; bl _s800310EC_11; mr 4,31; bl _s800310EC_12; 11:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800310EC_0();
extern "C" void _s800310EC_1();
extern "C" void _s800310EC_2();
extern "C" void _s800310EC_3();
extern "C" void _s800310EC_4();
extern "C" void _s800310EC_5();
extern "C" void _s800310EC_6();
extern "C" void _s800310EC_7();
extern "C" void _s800310EC_8();
extern "C" void _s800310EC_9();
extern "C" void _s800310EC_10();
extern "C" void _s800310EC_11();
extern "C" void _s800310EC_12();
extern "C" void f_800310EC() {}
