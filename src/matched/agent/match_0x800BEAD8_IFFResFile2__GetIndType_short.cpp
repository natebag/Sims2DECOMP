// 0x800BEAD8 IFFResFile2::GetIndType(short) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BEAD8_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BEAD8_1; 1:; mr 3,31; bl _s800BEAD8_2; cmpwi 3,0; li 3,0; bne 3f; lwz 3,0x138(31); mr 4,30; bl _s800BEAD8_3; mr. 30,3; bne 2f; mr 3,31; li 4,-100; bl _s800BEAD8_4; 2:; mr 3,30; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BEAD8_0();
extern "C" void _s800BEAD8_1();
extern "C" void _s800BEAD8_2();
extern "C" void _s800BEAD8_3();
extern "C" void _s800BEAD8_4();
extern "C" void f_800BEAD8() {}
