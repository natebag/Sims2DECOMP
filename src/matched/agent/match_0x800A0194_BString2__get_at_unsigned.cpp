// 0x800A0194 BString2::get_at(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s800A0194_0; cmplw 30,3; blt 0f; bl _s800A0194_1; 0:; mr 3,31; bl _s800A0194_2; cmpwi 3,0; beq 1f; lwz 9,0x0(31); lwz 3,0x0(9); b 2f; 1:; li 3,0; 2:; add 9,30,30; lhzx 3,9,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A0194_0();
extern "C" void _s800A0194_1();
extern "C" void _s800A0194_2();
extern "C" void f_800A0194() {}
