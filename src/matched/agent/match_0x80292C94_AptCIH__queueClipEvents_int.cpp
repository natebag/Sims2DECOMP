// 0x80292C94 AptCIH::queueClipEvents(int, (1172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 15,0x1c(1); stw 0,0x64(1); stw 12,0x18(1); mr 31,3; mr 27,4; mr 24,5; mr 29,6; li 30,0; bl _s80292C94_0; cmpwi 3,15; bne 0f; mr 3,31; bl _s80292C94_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 1f; lwz 26,0x4c(31); mr 3,31; mr 4,27; bl _s80292C94_2; cmpwi 3,0; bne 2f; 1:; li 3,0; b 20f; 2:; lwz 11,0x20(26); cmpwi 2,29,0; li 23,0; cmpwi 11,0; beq 11f; lwz 0,0x0(11); li 21,0; cmpw 23,0; bge 11f; lis 9,-32694; lis 0,2; addi 28,9,-15980; cmpw cr3,27,0; lis 0,4; lis 9,-32694; addi 17,28,-16; cmpw cr4,27,0; addi 15,9,-11332; addi 22,1,16; lis 18,-32704; lis 19,-32704; lis 20,-32704; li 25,0; rlwinm 16,24,15,17,31; 3:; lwz 9,0x4(11); lwzx 0,25,9; add 30,25,9; and. 8,0,27; beq 10f; cmpwi 7,27,512; beq cr7,7f; bgt cr7,4f; cmpwi 27,2; beq 5f; cmpwi 27,4; beq 7f; b 9f; 4:; beq cr3,6f; beq cr4,7f; b 9f; 5:; lwz 3,-23008(13); addi 30,30,8; lwz 29,-27612(13); li 23,1; bl _s80292C94_3; mr 4,30; mr 6,29; mr 5,31; bl _s80292C94_4; b 10f; 6:; lwz 0,0x4(30); cmpw 0,16; bne 10f; lwz 3,-23008(13); addi 30,30,8; li 23,1; bl _s80292C94_5; mr 4,30; mr 5,31; mr 6,24; bl _s80292C94_6; b 10f; 7:; li 30,117; bne cr7,8f; li 30,107; 8:; lwz 9,0x0(28); lwz 10,0x4(28); rlwinm 30,30,2,0,29; lwz 3,-23016(13); li 4,72; stw 9,0x8(1); stw 10,0xc(1); li 23,1; bl _s80292C94_7; lwz 10,0x20(26); li 9,0; lwzx 7,30,15; addi 6,1,8; lwz 11,0x4(10); mr 8,31; addi 7,7,8; li 5,-1; add 11,25,11; lwz 4,0x8(11); bl _s80292C94_8; mr 30,3; mr 4,22; addi 3,28,-52; bl _s80292C94_9; lwz 11,-16(28); mr 29,3; lwz 10,0x8(17); lis 4,-32704; rlwinm 9,11,2,0,29; addi 4,4,23384; stwx 31,9,10; addi 11,11,1; stw 11,-16(28); addi 5,18,21404; li 6,120; lwz 9,0x8(31); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x8(30); addi 4,19,23484; addi 5,20,22800; li 6,2001; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,30,3; blrl; addi 3,28,-52; mr 4,31; mr 5,30; li 6,0; bl _s80292C94_10; lwz 9,0x8(30); addi 4,19,23484; addi 5,20,22800; li 6,2004; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,-16(28); lis 4,-32704; lwz 0,0x8(17); addi 4,4,21364; rlwinm 11,11,2,0,29; addi 5,18,21404; add 11,11,0; li 6,126; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,-16(28); mr 4,29; addi 3,28,-52; mr 5,22; addi 9,9,-1; stw 9,-16(28); bl _s80292C94_11; b 10f; 9:; lwz 9,0x20(26); li 23,1; lwz 3,-23008(13); lwz 30,0x4(9); add 30,25,30; bl _s80292C94_12; addi 30,30,8; mr 4,30; mr 5,31; mr 6,24; bl _s80292C94_13; 10:; lwz 11,0x20(26); addi 21,21,1; addi 25,25,12; lwz 0,0x0(11); cmpw 21,0; blt 3b; 11:; beq cr2,19f; lis 9,-32700; li 30,0; addi 9,9,-10248; li 11,0; lwzx 0,9,30; lwz 10,0x8(31); and. 8,0,27; bne 13f; 12:; addi 11,11,1; cmpwi 11,5; bgt 13f; lwzu 0,0x8(9); and. 8,0,27; beq 12b; mr 30,11; 13:; lha 3,0x20(10); rlwinm 29,30,3,0,28; lwz 0,0x24(10); add 3,31,3; mtspr 8,0; blrl; lis 9,-32700; lis 11,-32694; addi 27,9,-10248; addi 26,11,-11332; addi 28,27,4; lwzx 4,28,29; rlwinm 4,4,2,0,29; add 4,4,26; bl _s80292C94_14; mr. 30,3; beq 14f; lwzx 9,27,29; cmpwi 9,16384; beq 16f; cmpwi 9,8192; beq 16f; b 17f; 14:; lwzx 4,28,29; mr 3,31; li 5,0; rlwinm 4,4,2,0,29; add 4,4,26; bl _s80292C94_15; mr. 30,3; beq 19f; lwz 0,0x0(30); andis. 8,0,2048; beq 19f; lwz 0,0x24(30); cmpw 0,31; beq 15f; lwz 9,0x8(30); mr 4,31; lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,30,3; blrl; mr 30,3; li 9,1; lwz 0,0x0(30); rlwimi 0,9,8,18,23; stw 0,0x0(30); 15:; lwzx 9,27,29; cmpwi 9,16384; beq 16f; cmpwi 9,8192; beq 16f; cmpwi 9,1; bne 17f; 16:; lwz 3,-23008(13); bl _s80292C94_16; mr 4,31; mr 5,30; mr 7,24; li 6,0; bl _s80292C94_17; b 18f; 17:; lwz 3,-23008(13); bl _s80292C94_18; mr 4,31; mr 5,30; mr 7,24; li 6,0; bl _s80292C94_19; 18:; li 23,1; 19:; mr 3,23; 20:; lwz 0,0x64(1); lwz 12,0x18(1); mtspr 8,0; lmw 15,0x1c(1); mtcrf 56,12; addi 1,1,96"
extern "C" void _s80292C94_0();
extern "C" void _s80292C94_1();
extern "C" void _s80292C94_2();
extern "C" void _s80292C94_3();
extern "C" void _s80292C94_4();
extern "C" void _s80292C94_5();
extern "C" void _s80292C94_6();
extern "C" void _s80292C94_7();
extern "C" void _s80292C94_8();
extern "C" void _s80292C94_9();
extern "C" void _s80292C94_10();
extern "C" void _s80292C94_11();
extern "C" void _s80292C94_12();
extern "C" void _s80292C94_13();
extern "C" void _s80292C94_14();
extern "C" void _s80292C94_15();
extern "C" void _s80292C94_16();
extern "C" void _s80292C94_17();
extern "C" void _s80292C94_18();
extern "C" void _s80292C94_19();
extern "C" void f_80292C94() {}
