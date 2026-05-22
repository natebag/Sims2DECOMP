// 0x80231700 ERLevel::~ERLevel(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; addi 9,9,-25968; addis 31,29,3; stw 9,0x0(29); li 30,0; mr 28,4; stw 30,-23888(31); addi 4,31,-7440; bl _s80231700_0; mr 3,29; addi 4,31,-7256; bl _s80231700_1; lwz 3,-7456(31); cmpwi 3,0; beq 0f; bl _s80231700_2; stw 30,-7456(31); 0:; lwz 3,-7452(31); cmpwi 3,0; beq 1f; bl _s80231700_3; stw 30,-7452(31); 1:; lwz 3,-26392(13); mr 30,31; lwz 4,-7460(31); lwz 9,0x0(3); lha 0,0xa8(9); lwz 9,0xac(9); add 3,3,0; mtspr 8,9; blrl; mr 3,29; bl _s80231700_4; lwz 3,-26512(13); mr 4,29; bl _s80231700_5; lwz 4,-23936(31); cmpwi 4,0; beq 4f; lwz 0,-8(4); mulli 0,0,12; add 31,4,0; cmpw 4,31; beq 3f; 2:; addi 31,31,-12; mr 3,31; bl _s80231700_6; lwz 0,-23936(30); cmpw 0,31; bne 2b; 3:; lwz 3,-23936(30); addi 3,3,-8; bl _s80231700_7; 4:; lwz 3,-23932(30); li 31,0; stw 31,-23936(30); cmpwi 3,0; beq 5f; bl _s80231700_8; 5:; lwz 3,-23928(30); stw 31,-23932(30); cmpwi 3,0; beq 6f; bl _s80231700_9; 6:; stw 31,-23928(30); addi 3,30,-7256; li 4,2; bl _s80231700_10; li 4,2; addi 3,30,-7440; bl _s80231700_11; addi 3,30,-23900; bl _s80231700_12; addi 3,30,-23912; bl _s80231700_13; addi 3,30,-23948; bl _s80231700_14; li 4,2; addi 3,30,-23964; bl _s80231700_15; addi 3,30,-24204; bl _s80231700_16; mr 3,29; li 4,0; bl _s80231700_17; andi. 0,28,1; beq 7f; lis 3,-32696; mr 4,29; addi 3,3,32332; bl _s80231700_18; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80231700_0();
extern "C" void _s80231700_1();
extern "C" void _s80231700_2();
extern "C" void _s80231700_3();
extern "C" void _s80231700_4();
extern "C" void _s80231700_5();
extern "C" void _s80231700_6();
extern "C" void _s80231700_7();
extern "C" void _s80231700_8();
extern "C" void _s80231700_9();
extern "C" void _s80231700_10();
extern "C" void _s80231700_11();
extern "C" void _s80231700_12();
extern "C" void _s80231700_13();
extern "C" void _s80231700_14();
extern "C" void _s80231700_15();
extern "C" void _s80231700_16();
extern "C" void _s80231700_17();
extern "C" void _s80231700_18();
extern "C" void f_80231700() {}
