// 0x800A1814 BString2::find_last_of_str(unsigned (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 31,5; mr 26,4; mr 28,6; li 27,0; bl _s800A1814_0; cmplw 31,3; bge 0f; addi 30,31,1; b 1f; 0:; mr 3,29; bl _s800A1814_1; mr 30,3; 1:; mr 3,29; bl _s800A1814_2; cmpwi 3,0; beq 8f; 2:; cmpwi 30,0; beq 8f; li 27,0; addi 30,30,-1; cmpw 27,28; beq 2b; mr 31,26; 3:; mr 3,29; bl _s800A1814_3; cmpwi 3,0; beq 4f; lwz 9,0x0(29); lwz 10,0x0(9); b 5f; 4:; li 10,0; 5:; add 9,30,30; lhz 11,0x0(31); lhzx 0,9,10; li 9,1; cmpw 0,11; bne 6f; li 9,0; 6:; cmpwi 9,0; beq 7f; addi 27,27,1; addi 31,31,2; cmpw 27,28; bne 3b; 7:; cmpw 27,28; bne 9f; b 2b; 8:; cmpw 27,28; beq 10f; 9:; mr 3,29; bl _s800A1814_4; cmpwi 3,0; mr 3,30; bne 11f; 10:; li 3,-1; 11:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800A1814_0();
extern "C" void _s800A1814_1();
extern "C" void _s800A1814_2();
extern "C" void _s800A1814_3();
extern "C" void _s800A1814_4();
extern "C" void f_800A1814() {}
