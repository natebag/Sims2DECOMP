// 0x80094B68 PreGameCasPlayer2State::Reset(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s80094B68_0; lis 9,-32697; addi 31,9,23428; addi 3,31,260; bl _s80094B68_1; mr. 30,3; beq 0f; mr 3,30; bl _s80094B68_2; lha 30,0x4(30); lis 3,-32706; addi 3,3,-31376; mr 4,30; bl _s80094B68_3; mr 3,31; mr 4,30; li 5,0; bl _s80094B68_4; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80094B68_0();
extern "C" void _s80094B68_1();
extern "C" void _s80094B68_2();
extern "C" void _s80094B68_3();
extern "C" void _s80094B68_4();
extern "C" void f_80094B68() {}
