// 0x80261FE8 __VIRetraceHandler (628 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 5,3,8192; lis 3,-32694; stwu 1,-760(1); li 7,0; stmw 27,0x2e4(1); addi 30,4,0; addi 31,3,-16744; lhzu 6,0x30(5); rlwinm. 0,6,0,16,16; beq 0f; rlwinm 0,6,0,17,15; sth 0,0x0(5); ori 7,7,1; 0:; lis 3,-13312; lhzu 4,0x2034(3); rlwinm. 0,4,0,16,16; beq 1f; rlwinm 0,4,0,17,15; sth 0,0x0(3); ori 7,7,2; 1:; lis 3,-13312; lhzu 4,0x2038(3); rlwinm. 0,4,0,16,16; beq 2f; rlwinm 0,4,0,17,15; sth 0,0x0(3); ori 7,7,4; 2:; lis 3,-13312; lhzu 4,0x203c(3); rlwinm. 0,4,0,16,16; beq 3f; rlwinm 0,4,0,17,15; sth 0,0x0(3); ori 7,7,8; 3:; rlwinm. 0,7,0,29,29; bne 4f; rlwinm. 0,7,0,28,28; beq 6f; 4:; addi 3,1,24; bl _s80261FE8_0; addi 3,1,24; bl _s80261FE8_1; lwz 0,-23260(13); cmplwi 0,0; beq 5f; addi 3,1,22; addi 4,1,20; bl _s80261FE8_2; lwz 12,-23260(13); lha 3,0x16(1); mtspr 8,12; lha 4,0x14(1); blrl; 5:; addi 3,1,24; bl _s80261FE8_3; mr 3,30; bl _s80261FE8_4; b 17f; 6:; lwz 4,-23284(13); addi 3,1,24; addi 0,4,1; stw 0,-23284(13); bl _s80261FE8_5; addi 3,1,24; bl _s80261FE8_6; lwz 12,-23268(13); cmplwi 12,0; beq 7f; lwz 3,-23284(13); mtspr 8,12; blrl; 7:; lwz 0,-23280(13); cmplwi 0,0; beq 15f; lwz 0,-23232(13); cmplwi 0,1; bne 8f; bl _s80261FE8_7; cmplwi 3,0; beq 13f; 8:; lis 3,-13312; addi 29,3,8192; b 12f; 9:; lwz 3,-23224(13); li 5,32; lwz 27,-23220(13); addi 4,27,0; bl _s80261FE8_8; cntlzw 4,4; cmpwi 4,32; li 0,-1; and 0,27,0; bge 10f; b 11f; 10:; cntlzw 3,0; addi 4,3,32; 11:; rlwinm 6,4,1,0,30; add 3,31,6; lhz 0,0x78(3); subfic 5,4,63; li 3,0; sthx 0,29,6; li 4,1; bl _s80261FE8_9; lwz 0,-23224(13); not 5,3; not 4,4; lwz 3,-23220(13); and 0,0,5; and 3,3,4; stw 3,-23220(13); stw 0,-23224(13); 12:; lwz 0,-23224(13); li 4,0; lwz 3,-23220(13); xor 0,0,4; xor 3,3,4; or. 0,3,0; bne 9b; stw 4,-23232(13); li 4,1; lwz 0,-23208(13); lwz 3,0x144(31); stw 3,-23216(13); lwz 3,0x118(31); stw 3,-23212(13); stw 0,-23204(13); b 14f; 13:; li 4,0; 14:; cmpwi 4,0; beq 15f; li 0,0; stw 0,-23280(13); bl _s80261FE8_10; 15:; lwz 0,-23264(13); cmplwi 0,0; beq 16f; addi 3,1,24; bl _s80261FE8_11; lwz 12,-23264(13); lwz 3,-23284(13); mtspr 8,12; blrl; 16:; addi 3,13,-23276; bl _s80261FE8_12; addi 3,1,24; bl _s80261FE8_13; mr 3,30; bl _s80261FE8_14; 17:; lmw 27,0x2e4(1); lwz 0,0x2fc(1); addi 1,1,760; mtspr 8,0"
extern "C" void _s80261FE8_0();
extern "C" void _s80261FE8_1();
extern "C" void _s80261FE8_2();
extern "C" void _s80261FE8_3();
extern "C" void _s80261FE8_4();
extern "C" void _s80261FE8_5();
extern "C" void _s80261FE8_6();
extern "C" void _s80261FE8_7();
extern "C" void _s80261FE8_8();
extern "C" void _s80261FE8_9();
extern "C" void _s80261FE8_10();
extern "C" void _s80261FE8_11();
extern "C" void _s80261FE8_12();
extern "C" void _s80261FE8_13();
extern "C" void _s80261FE8_14();
extern "C" void f_80261FE8() {}
