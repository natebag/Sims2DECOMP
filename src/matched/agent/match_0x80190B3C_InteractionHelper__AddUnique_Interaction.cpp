// 0x80190B3C InteractionHelper::AddUnique(Interaction (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 21,0x2c(1); stw 0,0x5c(1); mr 24,3; addi 30,1,16; mr 25,4; addi 3,1,8; bl _s80190B3C_0; mr 22,30; addi 29,1,24; mr 3,30; bl _s80190B3C_1; mr 23,29; li 3,28; li 27,0; bl _s80190B3C_2; mr 28,3; lis 9,-32698; li 0,0; addi 21,9,27152; addi 26,28,20; stw 0,0x10(28); stw 0,0x0(28); mr 3,26; stw 0,0x4(28); mr 31,28; stw 0,0x8(28); stw 0,0xc(28); stw 21,0x18(28); bl _s80190B3C_3; mr 3,25; bl _s80190B3C_4; mr 4,3; li 5,0; li 6,-1; mr 3,29; bl _s80190B3C_5; mr 3,29; li 4,47; li 5,1; bl _s80190B3C_6; cmpwi 3,-1; beq 0f; addi 30,1,32; mr 6,3; li 5,0; mr 3,30; mr 4,23; bl _s80190B3C_7; addi 3,1,8; mr 4,30; bl _s80190B3C_8; li 4,2; mr 3,30; bl _s80190B3C_9; addi 3,1,8; bl _s80190B3C_10; addi 5,3,1; li 6,-1; mr 3,30; mr 4,23; bl _s80190B3C_11; mr 4,30; mr 3,22; bl _s80190B3C_12; li 4,2; mr 3,30; bl _s80190B3C_13; li 3,28; bl _s80190B3C_14; mr 9,3; addi 30,9,20; stw 27,0x10(9); stw 27,0x0(9); mr 3,30; stw 27,0x4(9); stw 27,0x8(9); stw 27,0xc(9); mr 27,9; stw 21,0x18(9); bl _s80190B3C_15; stw 31,0x8(27); mr 4,22; mr 3,30; bl _s80190B3C_16; stw 25,0x10(27); mr 3,26; stw 31,0x0(27); addi 4,1,8; bl _s80190B3C_17; stw 27,0xc(31); b 1f; 0:; mr 3,26; mr 4,23; bl _s80190B3C_18; stw 25,0x10(31); 1:; lwz 29,0x0(24); cmpwi 29,0; beq 7f; cmpwi 28,0; beq 11f; 2:; lwz 30,0x4(29); addi 3,29,20; addi 4,1,8; bl _s80190B3C_19; cmpwi 3,0; beq 6f; lwz 9,0xc(29); b 4f; 3:; lwz 9,0xc(9); 4:; lwz 0,0xc(9); cmpwi 0,0; bne 3b; stw 27,0xc(9); cmpwi 31,0; stw 29,0x8(27); stw 9,0x0(27); beq 5f; lwz 9,0x18(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 5:; li 31,0; li 30,0; 6:; mr. 29,30; beq 7f; cmpwi 31,0; bne 2b; 7:; cmpwi 31,0; beq 11f; lwz 0,0x0(24); cmpwi 0,0; bne 8f; stw 31,0x0(24); b 11f; 8:; mr 9,0; b 10f; 9:; lwz 9,0x4(9); 10:; lwz 0,0x4(9); cmpwi 0,0; bne 9b; stw 31,0x4(9); stw 9,0x0(31); 11:; mr 3,23; li 4,2; bl _s80190B3C_20; mr 3,22; li 4,2; bl _s80190B3C_21; addi 3,1,8; li 4,2; bl _s80190B3C_22; lwz 0,0x5c(1); mtspr 8,0; lmw 21,0x2c(1); addi 1,1,88"
extern "C" void _s80190B3C_0();
extern "C" void _s80190B3C_1();
extern "C" void _s80190B3C_2();
extern "C" void _s80190B3C_3();
extern "C" void _s80190B3C_4();
extern "C" void _s80190B3C_5();
extern "C" void _s80190B3C_6();
extern "C" void _s80190B3C_7();
extern "C" void _s80190B3C_8();
extern "C" void _s80190B3C_9();
extern "C" void _s80190B3C_10();
extern "C" void _s80190B3C_11();
extern "C" void _s80190B3C_12();
extern "C" void _s80190B3C_13();
extern "C" void _s80190B3C_14();
extern "C" void _s80190B3C_15();
extern "C" void _s80190B3C_16();
extern "C" void _s80190B3C_17();
extern "C" void _s80190B3C_18();
extern "C" void _s80190B3C_19();
extern "C" void _s80190B3C_20();
extern "C" void _s80190B3C_21();
extern "C" void _s80190B3C_22();
extern "C" void f_80190B3C() {}
