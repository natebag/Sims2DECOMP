// 0x800A01F8 BString2::operator[](unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s800A01F8_0; cmplw 30,3; bge 2f; mr 3,31; bl _s800A01F8_1; cmpwi 3,0; beq 0f; lwz 9,0x0(31); lwz 3,0x0(9); b 1f; 0:; li 3,0; 1:; add 9,30,30; lhzx 3,9,3; b 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A01F8_0();
extern "C" void _s800A01F8_1();
extern "C" void f_800A01F8() {}
