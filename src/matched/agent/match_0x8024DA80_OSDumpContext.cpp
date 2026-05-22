// 0x8024DA80 OSDumpContext (680 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-760(1); stmw 25,0x2dc(1); mr 28,3; lis 3,-32700; crxor 6,6,6; addi 31,3,-19984; mr 3,31; mr 4,28; bl _s8024DA80_0; li 25,0; rlwinm 0,25,2,0,29; add 27,28,0; b 0f; 0:; b 1f; 1:; b 2f; 2:; lwz 8,0x40(27); mr 4,25; lwz 5,0x0(27); addi 3,31,68; crxor 6,6,6; mr 6,5; mr 9,8; addi 7,25,16; bl _s8024DA80_1; addi 27,27,4; addi 25,25,1; cmplwi 25,16; blt 2b; lwz 4,0x84(28); addi 3,31,116; lwz 5,0x80(28); crxor 6,6,6; bl _s8024DA80_2; lwz 4,0x198(28); addi 3,31,164; lwz 5,0x19c(28); crxor 6,6,6; bl _s8024DA80_3; addi 3,31,212; crxor 6,6,6; bl _s8024DA80_4; li 25,0; rlwinm 0,25,2,0,29; add 27,28,0; b 3f; 3:; b 4f; 4:; b 5f; 5:; lwz 5,0x1a4(27); mr 4,25; lwz 7,0x1b4(27); addi 3,31,232; addi 6,25,4; crxor 6,6,6; bl _s8024DA80_5; addi 27,27,4; addi 25,25,1; cmplwi 25,4; blt 5b; lhz 0,0x1a2(28); rlwinm 0,0,0,31,31; cmplwi 0,0; beq 14f; bl _s8024DA80_6; lis 6,-32768; lwz 0,0xd4(6); li 5,0; addi 4,1,16; sth 5,0x1b0(1); mr 30,0; mr 29,3; sth 5,0x1b2(1); lwz 0,0xd8(6); cmplw 4,0; bne 6f; stw 5,0xd8(6); 6:; addi 3,1,16; bl _s8024DA80_7; addi 3,31,268; crxor 6,6,6; bl _s8024DA80_8; li 25,0; rlwinm 0,25,3,0,28; add 26,28,0; b 7f; 7:; b 8f; 8:; b 9f; 9:; lfd f1,0x98(26); bl _s8024DA80_9; mr 27,3; lfd f1,0x90(26); bl _s8024DA80_10; mr 5,3; crxor 6,6,6; mr 4,25; mr 7,27; addi 3,31,288; addi 6,25,1; bl _s8024DA80_11; addi 26,26,16; addi 25,25,2; cmplwi 25,32; blt 9b; addi 3,31,316; crxor 6,6,6; bl _s8024DA80_12; li 25,0; rlwinm 0,25,3,0,28; add 26,28,0; b 10f; 10:; b 11f; 11:; b 12f; 12:; lfd f1,0x1d0(26); bl _s8024DA80_13; mr 27,3; lfd f1,0x1c8(26); bl _s8024DA80_14; mr 5,3; crxor 6,6,6; mr 4,25; mr 7,27; addi 3,31,336; addi 6,25,1; bl _s8024DA80_15; addi 26,26,16; addi 25,25,2; cmplwi 25,32; blt 12b; li 5,0; sth 5,0x1b0(1); lis 3,-32768; addi 4,1,16; sth 5,0x1b2(1); lwz 0,0xd8(3); cmplw 4,0; bne 13f; stw 5,0xd8(3); 13:; mr 3,30; bl _s8024DA80_16; mr 3,29; bl _s8024DA80_17; 14:; addi 3,31,368; crxor 6,6,6; bl _s8024DA80_18; lwz 25,0x4(28); li 26,0; b 15f; 15:; b 16f; 16:; b 18f; 17:; lwz 5,0x0(25); mr 4,25; lwz 6,0x4(25); addi 3,31,408; crxor 6,6,6; bl _s8024DA80_19; lwz 25,0x0(25); 18:; cmplwi 25,0; beq 19f; addis 0,25,1; cmplwi 0,65535; beq 19f; cmplwi 26,16; addi 26,26,1; blt 17b; 19:; lmw 25,0x2dc(1); lwz 0,0x2fc(1); addi 1,1,760; mtspr 8,0"
extern "C" void _s8024DA80_0();
extern "C" void _s8024DA80_1();
extern "C" void _s8024DA80_2();
extern "C" void _s8024DA80_3();
extern "C" void _s8024DA80_4();
extern "C" void _s8024DA80_5();
extern "C" void _s8024DA80_6();
extern "C" void _s8024DA80_7();
extern "C" void _s8024DA80_8();
extern "C" void _s8024DA80_9();
extern "C" void _s8024DA80_10();
extern "C" void _s8024DA80_11();
extern "C" void _s8024DA80_12();
extern "C" void _s8024DA80_13();
extern "C" void _s8024DA80_14();
extern "C" void _s8024DA80_15();
extern "C" void _s8024DA80_16();
extern "C" void _s8024DA80_17();
extern "C" void _s8024DA80_18();
extern "C" void _s8024DA80_19();
extern "C" void f_8024DA80() {}
