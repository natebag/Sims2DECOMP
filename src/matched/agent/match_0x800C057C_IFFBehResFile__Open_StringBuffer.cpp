// 0x800C057C IFFBehResFile::Open(StringBuffer (1136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-488(1); mfspr 0,8; stmw 24,0x1c8(1); stw 0,0x1ec(1); mr 28,3; mr 27,4; lwz 9,0xc(28); lha 3,0x60(9); lwz 0,0x64(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 3,-47; b 21f; 0:; li 24,0; li 26,0; addi 3,1,88; addi 4,1,96; li 5,260; bl _s800C057C_0; addi 29,28,16; addi 30,1,88; addi 4,1,368; addi 3,1,360; li 5,12; bl _s800C057C_1; mr 31,29; addi 5,1,360; mr 4,30; mr 3,27; mr 25,30; bl _s800C057C_2; lis 4,-32706; mr 3,30; addi 4,4,-24852; li 5,-1; bl _s800C057C_3; mr 3,29; mr 4,27; bl _s800C057C_4; mr. 29,3; beq 1f; mr 3,31; mr 4,25; bl _s800C057C_5; mr 29,3; b 2f; 1:; li 24,1; 2:; cmpwi 29,0; bne 9f; li 0,64; mr 3,31; stw 0,0x1c0(1); li 4,0; bl _s800C057C_6; mr. 29,3; bne 8f; addi 30,1,384; mr 3,31; mr 4,30; addi 5,1,448; bl _s800C057C_7; mr. 29,3; bne 8f; lis 9,-32702; li 11,0; addi 9,9,16524; lbzx 9,9,29; cmpwi 9,42; beq 3f; lbzx 0,30,29; b 4f; 3:; addi 11,11,1; cmpwi 11,63; bgt 5f; lis 9,-32702; addi 9,9,16524; lbzx 9,9,11; cmpwi 9,42; beq 3b; lbzx 0,30,11; 4:; cmpw 9,0; beq 3b; li 29,-93; 5:; cmpwi 29,0; bne 8f; lbz 9,0x189(1); lbz 11,0x18b(1); addi 9,9,-48; rlwinm 9,9,8,0,23; addi 11,11,-48; or 9,9,11; extsh 9,9; cmpwi 9,512; beq 7f; cmpwi 9,517; bne 6f; lbz 11,0x1bc(1); lbz 0,0x1bd(1); lbz 9,0x1be(1); rlwinm 26,11,24,0,7; rlwinm 0,0,16,0,15; lbz 11,0x1bf(1); or 26,26,0; rlwinm 9,9,8,0,23; or 26,26,9; or 26,26,11; stw 26,0x140(28); b 7f; 6:; li 29,-93; 7:; cmpwi 29,0; beq 9f; 8:; mr 3,31; bl _s800C057C_8; cmpwi 29,0; 9:; mr 3,29; bne 21f; li 3,20; bl _s800C057C_9; stw 3,0x138(28); cmpwi 26,0; stw 29,0x0(3); stw 29,0x4(3); stw 29,0xc(3); stw 29,0x10(3); beq 13f; mr 3,28; addi 4,1,8; mr 5,26; bl _s800C057C_10; cmpwi 3,0; bne 12f; lhz 0,0x12(1); andi. 9,0,4; bne 12f; lwz 9,0x8(1); lis 0,29299; ori 0,0,28016; cmpw 9,0; bne 12f; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; bl _s800C057C_11; lha 0,0x10(1); mr 30,3; addi 4,1,96; li 5,64; stw 0,0x4(30); mr 3,25; lhz 0,0x12(1); stw 26,0x0(30); sth 0,0x8(30); bl _s800C057C_12; addi 4,1,20; li 5,-1; mr 3,25; bl _s800C057C_13; mr 4,25; addi 3,30,16; bl _s800C057C_14; stw 29,0xc(30); mr 3,28; mr 4,30; li 5,0; lwz 6,0x8(1); bl _s800C057C_15; lwz 31,0xc(30); cmpwi 3,0; bne 11f; cmpwi 31,0; beq 11f; stw 29,0xc(30); lis 5,29299; mr 4,31; ori 5,5,28016; lwz 3,0x138(28); li 6,0; bl _s800C057C_16; lwz 0,0x8(31); cmpwi 0,0; beq 10f; bl _s800C057C_17; lwz 4,0x4(31); bl _s800C057C_18; 10:; bl _s800C057C_19; mr 4,31; bl _s800C057C_20; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; li 5,0; li 6,0; bl _s800C057C_21; cmpwi 3,0; beq 13f; lwz 3,0x138(28); li 26,0; bl _s800C057C_22; b 13f; 11:; li 26,0; b 13f; 12:; li 26,0; li 29,-47; 13:; cmpwi 29,0; beq 14f; mr 3,29; b 21f; 14:; cmpwi 26,0; bne 19f; lis 27,16383; li 29,64; ori 27,27,65460; b 18f; 15:; lhz 0,0x12(1); andi. 31,0,4; beq 16f; lwz 9,0x138(28); lwz 0,0x10(9); add 0,0,11; stw 0,0x10(9); b 17f; 16:; lwz 3,0x138(28); lwz 4,0x8(1); bl _s800C057C_23; mr. 30,3; beq 17f; lha 0,0x10(1); addi 4,1,96; addi 3,1,88; li 5,64; stw 0,0x4(30); lhz 9,0x12(1); sth 9,0x8(30); lhz 0,0x12(1); stw 29,0x0(30); sth 0,0xa(30); bl _s800C057C_24; addi 3,1,88; addi 4,1,20; li 5,-1; bl _s800C057C_25; addi 3,30,16; addi 4,1,88; bl _s800C057C_26; stw 31,0xc(30); 17:; lwz 0,0xc(1); add 29,29,0; 18:; mr 3,28; addi 4,1,8; mr 5,29; bl _s800C057C_27; cmpwi 3,0; bne 19f; lwz 11,0xc(1); addi 0,11,-76; cmplw 0,27; ble 15b; 19:; lwz 9,0xc(28); lha 3,0x50(9); lwz 0,0x54(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; beq 20f; cmpwi 24,0; bne 20f; mr 3,28; bl _s800C057C_28; 20:; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; bl _s800C057C_29; li 0,0; li 3,0; stw 0,0x144(28); 21:; lwz 0,0x1ec(1); mtspr 8,0; lmw 24,0x1c8(1); addi 1,1,488"
extern "C" void _s800C057C_0();
extern "C" void _s800C057C_1();
extern "C" void _s800C057C_2();
extern "C" void _s800C057C_3();
extern "C" void _s800C057C_4();
extern "C" void _s800C057C_5();
extern "C" void _s800C057C_6();
extern "C" void _s800C057C_7();
extern "C" void _s800C057C_8();
extern "C" void _s800C057C_9();
extern "C" void _s800C057C_10();
extern "C" void _s800C057C_11();
extern "C" void _s800C057C_12();
extern "C" void _s800C057C_13();
extern "C" void _s800C057C_14();
extern "C" void _s800C057C_15();
extern "C" void _s800C057C_16();
extern "C" void _s800C057C_17();
extern "C" void _s800C057C_18();
extern "C" void _s800C057C_19();
extern "C" void _s800C057C_20();
extern "C" void _s800C057C_21();
extern "C" void _s800C057C_22();
extern "C" void _s800C057C_23();
extern "C" void _s800C057C_24();
extern "C" void _s800C057C_25();
extern "C" void _s800C057C_26();
extern "C" void _s800C057C_27();
extern "C" void _s800C057C_28();
extern "C" void _s800C057C_29();
extern "C" void f_800C057C() {}
