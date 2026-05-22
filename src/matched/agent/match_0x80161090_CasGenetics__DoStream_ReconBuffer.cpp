// 0x80161090 CasGenetics::DoStream(ReconBuffer (1068 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 22,0x28(1); stw 0,0x54(1); mr 28,3; mr 23,4; li 0,1; mr 22,5; stw 0,0xc(1); addi 4,1,12; mr 3,23; li 5,1; bl _s80161090_0; addi 31,28,16; lwz 10,0x10(28); addi 4,1,8; lwz 11,0x0(28); mr 3,23; lwz 9,0x4(31); li 5,1; lwz 0,0x4(28); subf 9,10,9; subf 0,11,0; srawi 9,9,2; srawi 0,0,2; sth 9,0x8(1); sth 0,0xa(1); bl _s80161090_1; mr 3,23; addi 4,1,10; li 5,1; bl _s80161090_2; lwz 0,0xc(23); cmpwi 0,0; bne 0f; mr 3,28; bl _s80161090_3; mr 3,31; li 4,26; bl _s80161090_4; mr 3,28; li 4,26; bl _s80161090_5; 0:; lha 0,0x8(1); li 25,0; cmpw 25,0; bge 14f; 1:; lwz 9,0xc(23); li 0,0; stw 0,0x10(1); rlwinm 26,25,2,0,29; cmpwi 9,0; bne 13f; li 3,8; addi 31,28,16; bl _s80161090_6; addi 24,1,16; bl _s80161090_7; stw 3,0x10(1); li 3,292; bl _s80161090_8; bl _s80161090_9; lwz 9,0x10(1); stw 3,0x0(9); lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 2f; stw 9,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 13f; 2:; lwz 0,0x10(28); li 9,1; stw 9,0x18(1); addi 10,1,24; subf 0,0,30; addi 11,1,20; srawi 9,0,2; stw 9,0x14(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 4f; mr 3,27; bl _s80161090_10; mr 29,3; b 6f; 4:; mr 3,27; bl _s80161090_11; mr 29,3; b 6f; 5:; li 29,0; li 27,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80161090_12; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 9,0x18(1); mr 30,0; rlwinm 26,25,2,0,29; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s80161090_13; b 12f; 11:; bl _s80161090_14; 12:; add 0,27,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 13:; lwz 9,0x10(28); lwzx 3,9,26; stw 3,0x10(1); cmpwi 3,0; beq 28f; lwz 3,0x0(3); cmpwi 3,0; beq 28f; mr 4,23; mr 5,22; bl _s80161090_15; addi 0,25,1; lha 9,0x8(1); extsh 25,0; cmpw 25,9; blt 1b; 14:; lha 0,0xa(1); li 25,0; cmpw 25,0; bge 28f; li 24,0; 15:; lwz 0,0xc(23); rlwinm 26,25,2,0,29; stw 24,0x1c(1); cmpwi 0,0; bne 27f; addi 27,1,28; li 3,8; bl _s80161090_16; bl _s80161090_17; stw 3,0x1c(1); li 3,292; bl _s80161090_18; bl _s80161090_19; lwz 9,0x1c(1); stw 3,0x0(9); lwz 30,0x4(28); lwz 0,0xc(28); cmpw 30,0; beq 16f; stw 9,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 27f; 16:; lwz 0,0x0(28); li 9,1; stw 9,0x24(1); addi 10,1,36; subf 0,0,30; addi 11,1,32; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 17f; mr 11,10; 17:; lwz 0,0x0(11); add. 0,9,0; beq 19f; rlwinm 0,0,2,0,29; mr 31,0; cmplwi 0,128; ble 18f; mr 3,31; bl _s80161090_20; mr 29,3; b 20f; 18:; mr 3,31; bl _s80161090_21; mr 29,3; b 20f; 19:; li 29,0; li 31,0; 20:; lwz 4,0x0(28); cmpw 30,4; beq 21f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80161090_22; add 0,3,30; b 22f; 21:; mr 0,29; 22:; lwz 9,0x24(1); mr 30,0; rlwinm 26,25,2,0,29; mtspr 9,9; cmpwi 9,0; beq 24f; 23:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 23b; 24:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 26f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 25f; bl _s80161090_23; b 26f; 25:; bl _s80161090_24; 26:; add 0,31,29; stw 29,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 27:; lwz 9,0x0(28); lwzx 3,9,26; stw 3,0x1c(1); cmpwi 3,0; beq 28f; lwz 3,0x0(3); cmpwi 3,0; beq 28f; mr 4,23; mr 5,22; bl _s80161090_25; addi 0,25,1; lha 9,0xa(1); extsh 25,0; cmpw 25,9; blt 15b; 28:; lwz 0,0x54(1); mtspr 8,0; lmw 22,0x28(1); addi 1,1,80"
extern "C" void _s80161090_0();
extern "C" void _s80161090_1();
extern "C" void _s80161090_2();
extern "C" void _s80161090_3();
extern "C" void _s80161090_4();
extern "C" void _s80161090_5();
extern "C" void _s80161090_6();
extern "C" void _s80161090_7();
extern "C" void _s80161090_8();
extern "C" void _s80161090_9();
extern "C" void _s80161090_10();
extern "C" void _s80161090_11();
extern "C" void _s80161090_12();
extern "C" void _s80161090_13();
extern "C" void _s80161090_14();
extern "C" void _s80161090_15();
extern "C" void _s80161090_16();
extern "C" void _s80161090_17();
extern "C" void _s80161090_18();
extern "C" void _s80161090_19();
extern "C" void _s80161090_20();
extern "C" void _s80161090_21();
extern "C" void _s80161090_22();
extern "C" void _s80161090_23();
extern "C" void _s80161090_24();
extern "C" void _s80161090_25();
extern "C" void f_80161090() {}
