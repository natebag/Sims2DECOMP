// 0x8009C0C8 BString::operator[](unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8009C0C8_0; cmplw 30,3; li 3,0; bge 0f; mr 3,31; bl _s8009C0C8_1; lbzx 3,3,30; extsb 3,3; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009C0C8_0();
extern "C" void _s8009C0C8_1();
extern "C" void f_8009C0C8() {}
