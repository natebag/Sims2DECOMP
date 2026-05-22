// 0x80383B00 CARDOpen (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,-1; stwu 1,-56(1); stmw 25,0x1c(1); addi 25,4,0; addi 30,5,0; addi 29,3,0; addi 4,1,20; stw 0,0x0(5); bl _s80383B00_0; cmpwi 3,0; bge 0f; b 8f; 0:; lwz 26,0x14(1); lwz 0,0x0(26); cmpwi 0,0; bne 1f; li 26,-3; b 4f; 1:; mr 3,26; bl _s80383B00_1; addi 27,3,0; li 28,0; 2:; addi 3,26,0; addi 4,27,0; bl _s80383B00_2; cmpwi 3,0; blt 3f; addi 3,27,0; addi 4,25,0; bl _s80383B00_3; cmpwi 3,0; beq 3f; addi 31,28,0; li 26,0; b 4f; 3:; addi 28,28,1; cmpwi 28,127; addi 27,27,64; blt 2b; li 26,-4; 4:; cmpwi 26,0; blt 7f; lwz 3,0x14(1); bl _s80383B00_4; rlwinm 0,31,6,0,25; add 5,3,0; lhz 4,0x36(5); cmplwi 4,5; blt 5f; lwz 3,0x14(1); lhz 0,0x10(3); cmplw 4,0; blt 6f; 5:; li 26,-6; b 7f; 6:; stw 29,0x0(30); li 0,0; stw 31,0x4(30); stw 0,0x8(30); lhz 0,0x36(5); sth 0,0x10(30); 7:; lwz 3,0x14(1); mr 4,26; bl _s80383B00_5; 8:; lmw 25,0x1c(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80383B00_0();
extern "C" void _s80383B00_1();
extern "C" void _s80383B00_2();
extern "C" void _s80383B00_3();
extern "C" void _s80383B00_4();
extern "C" void _s80383B00_5();
extern "C" void f_80383B00() {}
