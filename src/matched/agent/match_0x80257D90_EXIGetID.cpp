// 0x80257D90 EXIGetID (944 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-72(1); stmw 23,0x24(1); mr. 25,3; addi 26,4,0; addi 27,5,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bne 0f; cmplwi 26,2; bne 0f; lwz 0,-23568(13); cmplwi 0,0; beq 0f; stw 0,0x0(27); li 3,1; b 23f; 0:; cmpwi 25,2; bge 7f; cmplwi 26,0; bne 7f; mr 3,25; bl _s80257D90_0; cmpwi 3,0; bne 1f; li 3,0; b 23f; 1:; lwz 4,0x20(31); rlwinm 0,25,2,0,29; lis 3,-32768; addi 30,3,12480; add 30,30,0; lwz 0,0x0(30); cmpw 4,0; bne 2f; lwz 0,0x1c(31); stw 0,0x0(27); lwz 3,0x20(31); b 23f; 2:; bl _s80257D90_1; mr 28,3; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 3f; mr 3,25; bl _s80257D90_2; cmpwi 3,0; bne 4f; 3:; mr 3,28; bl _s80257D90_3; li 0,0; b 5f; 4:; addi 3,25,0; li 4,1; li 5,0; li 6,0; bl _s80257D90_4; li 0,0; stw 0,0x8(31); lis 3,16; mulli 0,25,3; srw 3,3,0; bl _s80257D90_5; lwz 0,0xc(31); ori 0,0,8; stw 0,0xc(31); mr 3,28; bl _s80257D90_6; li 0,1; 5:; cmpwi 0,0; bne 6f; li 3,0; b 23f; 6:; lwz 29,0x0(30); 7:; bl _s80257D90_7; addi 28,3,0; li 0,0; cmpwi 25,2; bge 8f; cmplwi 26,0; bne 8f; li 0,1; 8:; cmpwi 0,0; beq 9f; lis 3,-32731; addi 5,3,32104; b 10f; 9:; li 5,0; 10:; addi 3,25,0; addi 4,26,0; bl _s80257D90_8; cntlzw 0,3; rlwinm 0,0,27,5,31; mr. 30,0; bne 15f; addi 3,25,0; addi 4,26,0; li 5,0; bl _s80257D90_9; cntlzw 0,3; rlwinm 0,0,27,5,31; mr. 30,0; bne 11f; li 0,0; stw 0,0x1c(1); addi 3,25,0; addi 4,1,28; li 5,2; li 6,1; li 7,0; bl _s80257D90_10; cntlzw 0,3; rlwinm 0,0,27,5,31; or 30,30,0; addi 3,25,0; bl _s80257D90_11; cntlzw 0,3; rlwinm 0,0,27,5,31; or 30,30,0; addi 3,25,0; addi 4,27,0; li 5,4; li 6,0; li 7,0; bl _s80257D90_12; cntlzw 0,3; rlwinm 0,0,27,5,31; or 30,30,0; addi 3,25,0; bl _s80257D90_13; cntlzw 0,3; rlwinm 0,0,27,5,31; or 30,30,0; addi 3,25,0; bl _s80257D90_14; cntlzw 0,3; rlwinm 0,0,27,5,31; or 30,30,0; 11:; bl _s80257D90_15; mr 23,3; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; bne 12f; mr 3,23; bl _s80257D90_16; b 15f; 12:; lwz 0,0xc(31); rlwinm 0,0,0,28,26; stw 0,0xc(31); addi 3,25,0; addi 4,31,0; bl _s80257D90_17; lwz 3,0x24(31); cmpwi 3,0; ble 14f; lwz 24,0x2c(31); addic. 0,3,-1; stw 0,0x24(31); ble 13f; addi 3,31,40; addi 4,31,48; lwz 0,0x24(31); rlwinm 5,0,3,0,28; bl _s80257D90_18; 13:; addi 3,25,0; li 4,0; addi 12,24,0; mtspr 8,12; blrl; 14:; mr 3,23; bl _s80257D90_19; 15:; mr 3,28; bl _s80257D90_20; cmpwi 25,2; bge 21f; cmplwi 26,0; bne 21f; bl _s80257D90_21; mr 23,3; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 16f; mr 3,23; bl _s80257D90_22; b 18f; 16:; lwz 0,0xc(31); rlwinm. 0,0,0,27,27; beq 17f; lwz 0,0x18(31); cmplwi 0,0; bne 17f; mr 3,23; bl _s80257D90_23; b 18f; 17:; lwz 0,0xc(31); rlwinm 0,0,0,29,27; stw 0,0xc(31); lis 3,80; mulli 0,25,3; srw 3,3,0; bl _s80257D90_24; mr 3,23; bl _s80257D90_25; 18:; bl _s80257D90_26; rlwinm 0,25,2,0,29; lis 4,-32768; addi 4,4,12480; lwzx 0,4,0; subf 4,29,0; addic 0,4,-1; subfe 0,0,4; or. 30,30,0; bne 19f; lwz 0,0x0(27); stw 0,0x1c(31); stw 29,0x20(31); 19:; bl _s80257D90_27; cmpwi 30,0; beq 20f; li 3,0; b 23f; 20:; lwz 3,0x20(31); b 23f; 21:; cmpwi 30,0; beq 22f; li 3,0; b 23f; 22:; li 3,1; 23:; lwz 0,0x4c(1); lmw 23,0x24(1); addi 1,1,72; mtspr 8,0"
extern "C" void _s80257D90_0();
extern "C" void _s80257D90_1();
extern "C" void _s80257D90_2();
extern "C" void _s80257D90_3();
extern "C" void _s80257D90_4();
extern "C" void _s80257D90_5();
extern "C" void _s80257D90_6();
extern "C" void _s80257D90_7();
extern "C" void _s80257D90_8();
extern "C" void _s80257D90_9();
extern "C" void _s80257D90_10();
extern "C" void _s80257D90_11();
extern "C" void _s80257D90_12();
extern "C" void _s80257D90_13();
extern "C" void _s80257D90_14();
extern "C" void _s80257D90_15();
extern "C" void _s80257D90_16();
extern "C" void _s80257D90_17();
extern "C" void _s80257D90_18();
extern "C" void _s80257D90_19();
extern "C" void _s80257D90_20();
extern "C" void _s80257D90_21();
extern "C" void _s80257D90_22();
extern "C" void _s80257D90_23();
extern "C" void _s80257D90_24();
extern "C" void _s80257D90_25();
extern "C" void _s80257D90_26();
extern "C" void _s80257D90_27();
extern "C" void f_80257D90() {}
