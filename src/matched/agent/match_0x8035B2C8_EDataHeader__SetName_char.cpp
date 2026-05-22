// 0x8035B2C8 EDataHeader::SetName(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 28,3; bl _s8035B2C8_0; mr 30,3; mr 3,29; bl _s8035B2C8_1; addi 4,3,1; li 5,0; mr 3,30; bl _s8035B2C8_2; mr 4,29; stw 3,0x0(28); bl _s8035B2C8_3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035B2C8_0();
extern "C" void _s8035B2C8_1();
extern "C" void _s8035B2C8_2();
extern "C" void _s8035B2C8_3();
extern "C" void f_8035B2C8() {}
