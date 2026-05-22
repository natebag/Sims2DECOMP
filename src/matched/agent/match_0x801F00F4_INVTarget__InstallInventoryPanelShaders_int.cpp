// 0x801F00F4 INVTarget::InstallInventoryPanelShaders(int) (780 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 19,0x4c(1); stw 0,0x84(1); mr 31,3; mr 24,4; lwz 3,0x90(31); addi 30,31,216; li 21,0; bl _s801F00F4_0; li 20,0; stw 3,0xd4(31); li 4,0; li 5,48; mr 3,30; bl _s801F00F4_1; li 27,0; lwz 3,0x90(31); mr 5,30; mr 4,24; li 6,12; bl _s801F00F4_2; lis 9,-32704; lis 11,-32704; addi 19,9,-15780; lwz 26,-21508(13); lis 9,-32697; addi 25,11,-16548; addi 22,9,24012; 0:; lwz 0,0x84(31); addi 9,31,216; lwzx 28,9,27; mulli 0,0,48; sth 20,0x8(1); cmpwi 28,0; add 0,27,0; lwzx 23,19,0; beq 12f; cmpwi 24,2; bne 9f; mr 3,28; bl _s801F00F4_3; cmpwi 3,3; beq 4f; bgt 1f; cmpwi 3,1; beq 8f; cmpwi 3,2; beq 3f; b 10f; 1:; cmpwi 3,4; beq 2f; cmpwi 3,5; beq 5f; b 10f; 2:; lwz 0,0x84(31); lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,27,0; lwzx 4,25,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lis 5,-8422; lwz 6,0x7c(31); ori 5,5,36483; b 7f; 3:; mr 3,28; bl _s801F00F4_4; lwz 10,0x84(31); rlwinm 3,3,2,0,29; lwz 11,0xdc(22); mulli 10,10,48; lwz 0,0x0(31); lwz 9,0x0(11); cmpwi 0,0; lwzx 11,9,3; add 10,27,10; lwz 5,0x0(11); b 6f; 4:; mr 3,28; bl _s801F00F4_5; lwz 10,0x84(31); rlwinm 3,3,2,0,29; lwz 11,0xd4(22); mulli 10,10,48; lwz 0,0x0(31); lwz 9,0x0(11); cmpwi 0,0; lwzx 11,9,3; add 10,27,10; lwz 5,0xc(11); b 6f; 5:; mr 3,28; bl _s801F00F4_6; lwz 10,0x84(31); rlwinm 3,3,2,0,29; lwz 11,0xd8(22); mulli 10,10,48; lwz 0,0x0(31); lwz 9,0x0(11); cmpwi 0,0; lwzx 11,9,3; add 10,27,10; lwz 5,0x8(11); 6:; lwzx 4,25,10; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); 7:; li 7,0; bl _s801F00F4_7; b 10f; 8:; lwz 30,0x0(26); mr 3,28; lha 29,0x78(30); addi 30,30,120; add 29,26,29; bl _s801F00F4_8; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; bl _s801F00F4_9; lwz 30,0x84(31); mr 29,3; mr 3,28; mulli 30,30,48; add 30,27,30; bl _s801F00F4_10; lwz 0,0x0(31); mr 7,3; lwzx 4,25,30; cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); mr 5,29; bl _s801F00F4_11; b 10f; 9:; lwz 30,0x0(26); mr 3,28; lha 29,0x78(30); addi 30,30,120; add 29,26,29; bl _s801F00F4_12; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; bl _s801F00F4_13; lwz 30,0x84(31); mr 29,3; mr 3,28; mulli 30,30,48; add 30,27,30; bl _s801F00F4_14; lwz 0,0x0(31); mr 7,3; lwzx 4,25,30; cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); mr 5,29; bl _s801F00F4_15; 10:; mr 3,28; bl _s801F00F4_16; cmpwi 3,1; ble 11f; addi 4,1,8; bl _s801F00F4_17; b 12f; 11:; sth 20,0x8(1); 12:; mr 3,23; addi 4,1,8; bl _s801F00F4_18; addi 21,21,1; addi 27,27,4; cmplwi 21,11; ble 0b; lwz 0,0x84(1); mtspr 8,0; lmw 19,0x4c(1); addi 1,1,128"
extern "C" void _s801F00F4_0();
extern "C" void _s801F00F4_1();
extern "C" void _s801F00F4_2();
extern "C" void _s801F00F4_3();
extern "C" void _s801F00F4_4();
extern "C" void _s801F00F4_5();
extern "C" void _s801F00F4_6();
extern "C" void _s801F00F4_7();
extern "C" void _s801F00F4_8();
extern "C" void _s801F00F4_9();
extern "C" void _s801F00F4_10();
extern "C" void _s801F00F4_11();
extern "C" void _s801F00F4_12();
extern "C" void _s801F00F4_13();
extern "C" void _s801F00F4_14();
extern "C" void _s801F00F4_15();
extern "C" void _s801F00F4_16();
extern "C" void _s801F00F4_17();
extern "C" void _s801F00F4_18();
extern "C" void f_801F00F4() {}
