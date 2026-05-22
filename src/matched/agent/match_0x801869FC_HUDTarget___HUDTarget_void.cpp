// 0x801869FC HUDTarget::~HUDTarget(void) (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; mr 31,3; addi 9,9,26760; mr 26,4; stw 9,0x80(31); bl _s801869FC_0; lwz 0,0x0(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s801869FC_1; lwz 3,0x8(31); addi 4,31,56; bl _s801869FC_2; lwz 3,0xc(31); addi 4,31,72; bl _s801869FC_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s801869FC_4; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s801869FC_5; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s801869FC_6; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801869FC_7; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801869FC_8; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801869FC_9; 9:; lwz 29,0xa0(31); addi 28,31,1856; addi 27,31,264; cmpwi 29,0; beq 13f; lwz 9,0x0(29); cmpwi 9,0; beq 12f; lwz 0,-8(9); mulli 0,0,20; add 30,9,0; cmpw 9,30; beq 11f; 10:; addi 30,30,-20; li 4,0; mr 3,30; bl _s801869FC_10; lwz 0,0x0(29); cmpw 0,30; bne 10b; 11:; lwz 3,0x0(29); addi 3,3,-8; bl _s801869FC_11; 12:; li 30,0; mr 3,29; stw 30,0x0(29); bl _s801869FC_12; stw 30,0xa0(31); 13:; lwz 11,0x8b4(31); cmpwi 11,0; beq 14f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 14:; li 0,0; lis 9,-32697; addi 9,9,23428; stw 0,0x8b4(31); stw 0,0x48(9); cmpwi 28,0; beq 16f; addi 30,31,2216; cmpw 28,30; beq 16f; 15:; addi 30,30,-180; li 4,0; mr 3,30; bl _s801869FC_13; cmpw 28,30; bne 15b; 16:; cmpwi 27,0; beq 18f; mr 30,28; cmpw 27,30; beq 18f; 17:; addi 30,30,-796; li 4,0; mr 3,30; bl _s801869FC_14; cmpw 27,30; bne 17b; 18:; lis 9,-32698; andi. 0,26,1; addi 9,9,-12328; stw 9,0x80(31); beq 19f; mr 3,31; bl _s801869FC_15; 19:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801869FC_0();
extern "C" void _s801869FC_1();
extern "C" void _s801869FC_2();
extern "C" void _s801869FC_3();
extern "C" void _s801869FC_4();
extern "C" void _s801869FC_5();
extern "C" void _s801869FC_6();
extern "C" void _s801869FC_7();
extern "C" void _s801869FC_8();
extern "C" void _s801869FC_9();
extern "C" void _s801869FC_10();
extern "C" void _s801869FC_11();
extern "C" void _s801869FC_12();
extern "C" void _s801869FC_13();
extern "C" void _s801869FC_14();
extern "C" void _s801869FC_15();
extern "C" void f_801869FC() {}
