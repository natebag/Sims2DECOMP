// 0x80386D84 __CARDSetStatusExAsync (668 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 25,0x24(1); mr. 27,4; addi 26,3,0; addi 28,5,0; addi 29,6,0; blt 0f; cmpwi 27,127; bge 0f; lbz 0,0x8(28); cmplwi 0,255; beq 0f; cmplwi 0,0; bne 1f; 0:; li 3,-128; b 16f; 1:; addi 3,26,0; addi 4,1,24; bl _s80386D84_0; cmpwi 3,0; bge 2f; b 16f; 2:; lwz 3,0x18(1); bl _s80386D84_1; mr 0,3; lwz 3,0x18(1); mr 31,0; rlwinm 0,27,6,0,25; add 30,31,0; addi 4,30,0; bl _s80386D84_2; mr. 4,3; bge 3f; lwz 3,0x18(1); bl _s80386D84_3; b 16f; 3:; addi 4,28,8; addi 3,28,40; subf 0,4,3; cmplw 4,3; mtspr 9,0; bge 8f; 4:; lbz 0,0x0(4); cmplwi 0,0; bne 7f; addi 0,28,40; li 3,0; b 6f; 5:; stb 3,0x0(4); 6:; addi 4,4,1; cmplw 4,0; blt 5b; b 8f; 7:; addi 4,4,1; bdnz 4b; 8:; lbz 0,0x34(28); rlwinm. 0,0,0,26,26; beq 9f; addi 3,28,0; li 4,0; li 5,4; bl _s80386D84_4; addi 3,28,4; li 4,0; li 5,2; bl _s80386D84_5; 9:; lbz 0,0x34(28); rlwinm. 0,0,0,25,25; beq 10f; addi 3,28,0; li 4,0; li 5,4; bl _s80386D84_6; 10:; addi 3,30,8; addi 4,28,8; li 5,32; bl _s80386D84_7; cmpwi 3,0; bne 11f; addi 3,30,0; addi 4,28,0; li 5,4; bl _s80386D84_8; cmpwi 3,0; bne 11f; addi 3,30,4; addi 4,28,4; li 5,2; bl _s80386D84_9; cmpwi 3,0; beq 14f; 11:; li 25,0; 12:; cmpw 25,27; beq 13f; lbz 0,0x0(31); cmplwi 0,255; beq 13f; addi 3,31,0; addi 4,28,0; li 5,4; bl _s80386D84_10; cmpwi 3,0; bne 13f; addi 3,31,4; addi 4,28,4; li 5,2; bl _s80386D84_11; cmpwi 3,0; bne 13f; addi 3,31,8; addi 4,28,8; li 5,32; bl _s80386D84_12; cmpwi 3,0; bne 13f; lwz 3,0x18(1); li 4,-7; bl _s80386D84_13; b 16f; 13:; addi 25,25,1; cmpwi 25,127; addi 31,31,64; blt 12b; addi 3,30,8; addi 4,28,8; li 5,32; bl _s80386D84_14; addi 3,30,0; addi 4,28,0; li 5,4; bl _s80386D84_15; addi 3,30,4; addi 4,28,4; li 5,2; bl _s80386D84_16; 14:; lwz 0,0x28(28); addi 3,26,0; addi 4,29,0; stw 0,0x28(30); lbz 0,0x7(28); stb 0,0x7(30); lwz 0,0x2c(28); stw 0,0x2c(30); lhz 0,0x30(28); sth 0,0x30(30); lhz 0,0x32(28); sth 0,0x32(30); lwz 0,0x3c(28); stw 0,0x3c(30); lbz 0,0x34(28); stb 0,0x34(30); lbz 0,0x35(28); stb 0,0x35(30); bl _s80386D84_17; mr. 26,3; bge 15f; lwz 3,0x18(1); mr 4,26; bl _s80386D84_18; 15:; mr 3,26; 16:; lmw 25,0x24(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s80386D84_0();
extern "C" void _s80386D84_1();
extern "C" void _s80386D84_2();
extern "C" void _s80386D84_3();
extern "C" void _s80386D84_4();
extern "C" void _s80386D84_5();
extern "C" void _s80386D84_6();
extern "C" void _s80386D84_7();
extern "C" void _s80386D84_8();
extern "C" void _s80386D84_9();
extern "C" void _s80386D84_10();
extern "C" void _s80386D84_11();
extern "C" void _s80386D84_12();
extern "C" void _s80386D84_13();
extern "C" void _s80386D84_14();
extern "C" void _s80386D84_15();
extern "C" void _s80386D84_16();
extern "C" void _s80386D84_17();
extern "C" void _s80386D84_18();
extern "C" void f_80386D84() {}
