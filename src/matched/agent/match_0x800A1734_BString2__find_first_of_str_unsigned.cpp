// 0x800A1734 BString2::find_first_of_str(unsigned (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 26,4; mr 27,6; mr 30,5; b 6f; 0:; li 29,0; cmplw 29,27; bge 5f; mr 31,26; 1:; mr 3,28; bl _s800A1734_0; cmpwi 3,0; beq 2f; lwz 9,0x0(28); lwz 10,0x0(9); b 3f; 2:; li 10,0; 3:; add 9,30,30; lhz 11,0x0(31); lhzx 0,9,10; li 9,1; cmpw 0,11; bne 4f; li 9,0; 4:; cmpwi 9,0; beq 5f; addi 29,29,1; addi 31,31,2; cmplw 29,27; blt 1b; 5:; cmpw 29,27; bne 7f; addi 30,30,1; 6:; mr 3,28; bl _s800A1734_1; cmplw 30,3; blt 0b; 7:; mr 3,28; li 29,-1; bl _s800A1734_2; cmplw 30,3; bge 8f; mr 29,30; 8:; li 3,-1; cmplw 3,29; ble 9f; mr 3,29; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800A1734_0();
extern "C" void _s800A1734_1();
extern "C" void _s800A1734_2();
extern "C" void f_800A1734() {}
