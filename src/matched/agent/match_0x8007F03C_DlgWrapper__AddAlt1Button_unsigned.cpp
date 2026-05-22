// 0x8007F03C DlgWrapper::AddAlt1Button(unsigned (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 6,4; lwz 3,0xac(3); li 4,2; li 5,1; bl _s8007F03C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8007F03C_0();
extern "C" void f_8007F03C() {}
