// 0x80361728 EStringTableNoCase::operator[](char (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s80361728_0; mr 29,3; mr 5,30; mr 3,31; mr 4,29; bl _s80361728_1; mr. 3,3; bne 0f; mr 3,31; mr 4,29; mr 5,30; li 6,0; bl _s80361728_2; 0:; addi 3,3,16; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80361728_0();
extern "C" void _s80361728_1();
extern "C" void _s80361728_2();
extern "C" void f_80361728() {}
