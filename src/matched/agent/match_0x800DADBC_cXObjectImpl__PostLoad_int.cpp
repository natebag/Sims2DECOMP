// 0x800DADBC cXObjectImpl::PostLoad(int, (940 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,3; mr 27,4; lwz 0,0x80(29); mr 26,5; cmpwi 0,0; bne 0f; lwz 3,0x4(29); li 4,1; lwz 9,0x4(3); lha 0,0x1d8(9); lwz 9,0x1dc(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 3,0x4(29); addi 4,29,104; lwz 5,0x80(29); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 27,31; bgt 5f; addi 3,29,40; li 4,42; mr 31,3; bl _s800DADBC_0; lha 30,0x0(3); andi. 0,30,1; beq 1f; mr 3,31; li 4,42; rlwinm 5,30,0,31,29; bl _s800DADBC_1; b 3f; 1:; mr 3,31; li 4,42; bl _s800DADBC_2; lhz 0,0x0(3); andi. 9,0,2; beq 2f; mr 3,31; li 4,42; rlwinm 5,30,0,0,30; bl _s800DADBC_3; b 3f; 2:; ori 5,30,3; mr 3,31; li 4,42; bl _s800DADBC_4; 3:; mr 3,31; li 4,42; bl _s800DADBC_5; lha 30,0x0(3); andi. 0,30,128; beq 4f; li 5,-130; mr 3,31; and 5,30,5; li 4,42; bl _s800DADBC_6; 4:; li 4,43; mr 3,31; bl _s800DADBC_7; lha 5,0x0(3); li 4,43; mr 3,31; ori 5,5,10; bl _s800DADBC_8; 5:; cmpwi 27,32; bgt 11f; lwz 3,0x4(29); li 31,1; lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 10f; cmpwi 29,0; beq 6f; lwz 9,0x4(29); li 4,3; lwz 3,0x0(9); bl _s800DADBC_9; mr 11,3; b 7f; 6:; li 11,0; 7:; lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 8f; lwz 9,0x0(3); li 4,5; lwz 3,0x0(9); bl _s800DADBC_10; b 9f; 8:; li 3,0; 9:; lwz 0,0x4(29); cmpw 3,0; beq 10f; li 31,0; 10:; cmpwi 31,0; beq 11f; lwz 11,0x4(29); addi 28,29,40; lwz 9,0x4(11); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,11,3; blrl; bl _s800DADBC_11; lwz 9,0x38(3); li 4,41; mr 3,28; lha 30,0x4c(9); lha 31,0x24(9); bl _s800DADBC_12; lha 0,0x0(3); cmpw 0,30; bge 11f; mr 3,28; mr 5,31; li 4,41; bl _s800DADBC_13; 11:; cmpwi 27,34; bgt 12f; addi 3,29,40; li 4,4; li 5,1; bl _s800DADBC_14; 12:; cmpwi 26,0; beq 13f; li 0,1; sth 0,0x8(1); b 14f; 13:; sth 26,0x8(1); 14:; addi 11,1,8; li 0,0; sth 0,0x6(11); mr 30,11; sth 0,0x2(11); li 31,0; sth 0,0x4(11); lwz 9,0x8c(29); lwz 0,0x7c(9); andi. 9,0,2; beq 15f; lwz 0,-31900(13); cmpwi 0,0; beq 15f; li 31,1; 15:; lwz 11,-21508(13); cmpwi 31,0; mfcr 31; lwz 9,0x0(11); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x8c(29); mtcrf 128,31; xor 0,0,3; subfic 9,0,0; adde 0,9,0; bne 16f; cmpwi 0,0; beq 17f; 16:; lwz 11,0x58(29); lwz 4,0x4(29); lwz 9,0x0(11); lwz 0,0x134(9); lha 3,0x130(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xec(29); li 4,0; lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; mtcrf 128,31; beq 17f; lwz 3,0x4(29); li 4,0; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 17:; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; bne 18f; lwz 3,0x4(29); mr 6,30; li 4,2; li 5,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 18:; lwz 3,0x4(29); lwz 9,0x4(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s800DADBC_0();
extern "C" void _s800DADBC_1();
extern "C" void _s800DADBC_2();
extern "C" void _s800DADBC_3();
extern "C" void _s800DADBC_4();
extern "C" void _s800DADBC_5();
extern "C" void _s800DADBC_6();
extern "C" void _s800DADBC_7();
extern "C" void _s800DADBC_8();
extern "C" void _s800DADBC_9();
extern "C" void _s800DADBC_10();
extern "C" void _s800DADBC_11();
extern "C" void _s800DADBC_12();
extern "C" void _s800DADBC_13();
extern "C" void _s800DADBC_14();
extern "C" void f_800DADBC() {}
