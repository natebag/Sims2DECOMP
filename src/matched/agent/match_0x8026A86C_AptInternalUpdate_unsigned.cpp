// 0x8026A86C _AptInternalUpdate(unsigned (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-440(1); mfspr 0,8; stmw 24,0x198(1); stw 0,0x1bc(1); li 11,96; addi 9,1,8; mtspr 9,11; mr 26,3; mr 28,9; addi 27,1,400; addi 24,1,392; li 0,0; 0:; stw 0,0x0(9); addi 9,9,4; bdnz 0b; lwz 9,-23000(13); li 29,0; li 25,0; lwz 0,0x0(9); b 6f; 1:; lwz 3,0x0(3); mr 31,29; addi 29,29,1; stw 3,0x190(1); cmpwi 3,0; beq 2f; bl _s8026A86C_0; 2:; rlwinm 31,31,2,0,29; add 30,31,28; cmpw 27,30; beq 4f; lwzx 3,31,28; cmpwi 3,0; beq 3f; bl _s8026A86C_1; cmpwi 3,0; bne 3f; lwzx 3,31,28; bl _s8026A86C_2; 3:; lwz 3,0x190(1); stw 3,0x0(30); cmpwi 3,0; beq 4f; bl _s8026A86C_3; 4:; lwz 3,0x190(1); cmpwi 3,0; beq 5f; bl _s8026A86C_4; cmpwi 3,0; bne 5f; lwz 3,0x190(1); bl _s8026A86C_5; 5:; lwz 9,0x188(1); lwz 0,0x4(9); 6:; stw 0,0x188(1); lwz 3,0x188(1); li 0,1; stw 25,0x190(1); cmpwi 3,0; bne 7f; li 0,0; 7:; cmpwi 0,0; bne 1b; lis 9,-32694; lwz 0,-16052(9); cmpwi 0,0; beq 8f; mr 3,26; bl _s8026A86C_6; b 11f; 8:; lwz 9,-23008(13); lwz 11,0x28(9); lwz 10,0x0(11); lwz 31,0x54(10); cmpwi 31,0; beq 10f; mr 3,31; li 30,0; bl _s8026A86C_7; cmpwi 3,18; bne 9f; mr 3,31; bl _s8026A86C_8; subfic 0,3,0; adde 30,0,3; 9:; cmpwi 30,0; beq 10f; mr 3,26; bl _s8026A86C_9; cmpwi 3,0; beq 11f; bl _s8026A86C_10; b 11f; 10:; lwz 3,-22996(13); bl _s8026A86C_11; lwz 9,-23008(13); li 0,0; stw 0,0x34(9); 11:; lwz 3,-27600(13); bl _s8026A86C_12; lwz 0,-27604(13); cmpwi 0,0; beq 12f; bl _s8026A86C_13; li 0,0; stw 0,-27604(13); 12:; mr 31,24; 13:; cmpw 28,31; beq 14f; lwzu 3,-4(31); cmpwi 3,0; beq 13b; bl _s8026A86C_14; cmpwi 3,0; bne 13b; lwz 3,0x0(31); bl _s8026A86C_15; b 13b; 14:; lwz 0,0x1bc(1); mtspr 8,0; lmw 24,0x198(1); addi 1,1,440"
extern "C" void _s8026A86C_0();
extern "C" void _s8026A86C_1();
extern "C" void _s8026A86C_2();
extern "C" void _s8026A86C_3();
extern "C" void _s8026A86C_4();
extern "C" void _s8026A86C_5();
extern "C" void _s8026A86C_6();
extern "C" void _s8026A86C_7();
extern "C" void _s8026A86C_8();
extern "C" void _s8026A86C_9();
extern "C" void _s8026A86C_10();
extern "C" void _s8026A86C_11();
extern "C" void _s8026A86C_12();
extern "C" void _s8026A86C_13();
extern "C" void _s8026A86C_14();
extern "C" void _s8026A86C_15();
extern "C" void f_8026A86C() {}
