// 0x800D1FF8 _c2DArray::DoStream(ReconBuffer (748 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 27,0x24(1); stw 0,0x3c(1); stw 12,0x20(1); mr 31,4; mr 28,3; mr 29,5; li 30,0; addi 4,1,8; sth 30,0x8(1); mr 3,31; li 5,1; bl _s800D1FF8_0; addi 4,1,10; sth 30,0xa(1); mr 3,31; li 5,1; bl _s800D1FF8_1; lwz 0,0x8(28); addi 4,1,20; lwz 9,0x4(28); mr 3,31; stw 0,0x14(1); li 5,1; stw 9,0x18(1); bl _s800D1FF8_2; addi 4,1,24; mr 3,31; li 5,1; bl _s800D1FF8_3; mr 3,31; addi 4,28,20; li 5,1; bl _s800D1FF8_4; stw 29,0x1c(1); mr 3,31; addi 4,1,28; li 5,1; bl _s800D1FF8_5; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lwz 4,0x14(1); mr 3,28; lwz 5,0x18(1); bl _s800D1FF8_6; cmpwi 3,0; beq 20f; 0:; lwz 0,0x14(28); lwz 9,0x8(28); lwz 11,0x4(28); lwz 10,0xc(28); rlwinm 9,9,2,0,29; mullw 11,11,0; lwz 8,0x1c(1); add 9,9,10; lwz 29,0x0(10); lwz 0,-4(9); cmpwi 8,0; add 28,0,11; bne 1f; mr 4,29; mr 3,31; subf 5,4,28; bl _s800D1FF8_7; b 20f; 1:; lwz 0,0xc(31); cmpwi 0,1; bne 19f; cmplw 29,28; bge 20f; addi 27,1,12; 2:; mr 5,29; li 10,0; cmplw 29,28; bge 6f; 3:; addi 0,5,1; li 10,1; cmplw 0,28; bge 5f; lbz 0,0x1(5); lbz 9,0x0(5); extsb 11,0; cmpw 0,9; bne 5f; mr 9,11; 4:; addi 10,10,1; add 0,5,10; cmplw 0,28; bge 5f; lbzx 0,5,10; extsb 0,0; cmpw 0,9; beq 4b; 5:; cmpwi 10,7; bgt 6f; add 5,5,10; cmplw 5,28; blt 3b; 6:; cmpw 5,29; bne 7f; mr 30,10; li 0,1; b 8f; 7:; subf 30,29,5; li 0,0; 8:; cmpwi 30,32767; ble 9f; li 30,32767; 9:; cmpwi 4,0,0; mr 0,30; beq cr4,10f; ori 0,30,32768; 10:; sth 0,0xc(1); mr 3,31; mr 4,27; li 5,1; bl _s800D1FF8_8; beq cr4,11f; mr 3,31; mr 4,29; li 5,1; bl _s800D1FF8_9; b 12f; 11:; mr 3,31; mr 4,29; mr 5,30; bl _s800D1FF8_10; 12:; lwz 0,0x8(31); andi. 9,0,1; beq 13f; li 0,0; mr 3,31; stb 0,0xe(1); addi 4,1,14; li 5,1; bl _s800D1FF8_11; 13:; add 29,29,30; cmplw 29,28; blt 2b; b 20f; 14:; mr 3,31; addi 4,1,16; li 5,1; bl _s800D1FF8_12; lhz 0,0x10(1); rlwinm 30,0,0,17,31; rlwinm. 9,0,17,15,31; beq 16f; mr 3,31; mr 4,29; li 5,1; add 27,29,30; bl _s800D1FF8_13; li 9,1; cmpw 9,30; bge 17f; 15:; lbz 0,0x0(29); stbx 0,29,9; addi 9,9,1; cmpw 9,30; blt 15b; b 17f; 16:; mr 3,31; mr 4,29; mr 5,30; add 27,29,30; bl _s800D1FF8_14; 17:; lwz 0,0x8(31); andi. 9,0,1; beq 18f; mr 3,31; addi 4,1,18; li 5,1; bl _s800D1FF8_15; 18:; mr 29,27; 19:; cmplw 29,28; blt 14b; 20:; lwz 0,0x3c(1); lwz 12,0x20(1); mtspr 8,0; lmw 27,0x24(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s800D1FF8_0();
extern "C" void _s800D1FF8_1();
extern "C" void _s800D1FF8_2();
extern "C" void _s800D1FF8_3();
extern "C" void _s800D1FF8_4();
extern "C" void _s800D1FF8_5();
extern "C" void _s800D1FF8_6();
extern "C" void _s800D1FF8_7();
extern "C" void _s800D1FF8_8();
extern "C" void _s800D1FF8_9();
extern "C" void _s800D1FF8_10();
extern "C" void _s800D1FF8_11();
extern "C" void _s800D1FF8_12();
extern "C" void _s800D1FF8_13();
extern "C" void _s800D1FF8_14();
extern "C" void _s800D1FF8_15();
extern "C" void f_800D1FF8() {}
