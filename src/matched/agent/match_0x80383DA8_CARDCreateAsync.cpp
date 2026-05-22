// 0x80383DA8 CARDCreateAsync (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-72(1); stmw 23,0x24(1); addi 26,4,0; addi 25,3,0; addi 27,5,0; addi 28,6,0; addi 29,7,0; addi 3,26,0; bl _s80383DA8_0; cmplwi 3,32; ble 0f; li 3,-12; b 13f; 0:; addi 3,25,0; addi 4,1,28; bl _s80383DA8_1; cmpwi 3,0; bge 1f; b 13f; 1:; cmplwi 27,0; beq 2f; lwz 3,0x1c(1); lwz 4,0xc(3); divwu 0,27,4; mullw 0,0,4; subf. 0,0,27; beq 3f; 2:; li 3,-128; b 13f; 3:; lis 4,1; addi 30,4,-1; bl _s80383DA8_2; addi 31,3,0; addi 24,31,0; li 23,0; b 7f; 4:; lbz 0,0x0(24); cmplwi 0,255; bne 5f; rlwinm 0,30,0,16,31; cmplwi 0,65535; bne 6f; mr 30,23; b 6f; 5:; lwz 4,0x1c(1); addi 3,24,0; li 5,4; lwz 4,0x10c(4); bl _s80383DA8_3; cmpwi 3,0; bne 6f; lwz 4,0x1c(1); addi 3,24,4; li 5,2; lwz 4,0x10c(4); addi 4,4,4; bl _s80383DA8_4; cmpwi 3,0; bne 6f; addi 3,24,0; addi 4,26,0; bl _s80383DA8_5; cmpwi 3,0; beq 6f; lwz 3,0x1c(1); li 4,-7; bl _s80383DA8_6; b 13f; 6:; addi 24,24,64; addi 23,23,1; 7:; rlwinm 0,23,0,16,31; cmplwi 0,127; blt 4b; rlwinm 0,30,0,16,31; cmplwi 0,65535; bne 8f; lwz 3,0x1c(1); li 4,-8; bl _s80383DA8_7; b 13f; 8:; lwz 3,0x1c(1); bl _s80383DA8_8; lwz 4,0x1c(1); lhz 0,0x6(3); lwz 3,0xc(4); mullw 0,3,0; cmplw 0,27; bge 9f; addi 3,4,0; li 4,-9; bl _s80383DA8_9; b 13f; 9:; cmplwi 29,0; beq 10f; mr 0,29; b 11f; 10:; lis 3,-32712; addi 0,3,-4304; 11:; stw 0,0xd0(4); rlwinm 0,30,6,10,25; add 7,31,0; lwz 3,0x1c(1); rlwinm 29,30,0,16,31; addi 4,26,0; sth 30,0xbc(3); addi 3,7,8; li 5,32; lwz 6,0x1c(1); lwz 0,0xc(6); divwu 0,27,0; sth 0,0x38(7); bl _s80383DA8_10; lwz 4,0x1c(1); lis 3,-32712; addi 5,3,15480; stw 28,0xc0(4); mr 3,25; stw 25,0x0(28); stw 29,0x4(28); lwz 4,0x1c(1); lwz 0,0xc(4); divwu 4,27,0; bl _s80383DA8_11; mr. 4,3; bge 12f; lwz 3,0x1c(1); bl _s80383DA8_12; b 13f; 12:; mr 3,4; 13:; lmw 23,0x24(1); lwz 0,0x4c(1); addi 1,1,72; mtspr 8,0"
extern "C" void _s80383DA8_0();
extern "C" void _s80383DA8_1();
extern "C" void _s80383DA8_2();
extern "C" void _s80383DA8_3();
extern "C" void _s80383DA8_4();
extern "C" void _s80383DA8_5();
extern "C" void _s80383DA8_6();
extern "C" void _s80383DA8_7();
extern "C" void _s80383DA8_8();
extern "C" void _s80383DA8_9();
extern "C" void _s80383DA8_10();
extern "C" void _s80383DA8_11();
extern "C" void _s80383DA8_12();
extern "C" void f_80383DA8() {}
