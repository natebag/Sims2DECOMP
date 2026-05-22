// 0x8009C07C BString::get_at(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8009C07C_0; cmplw 30,3; blt 0f; bl _s8009C07C_1; 0:; mr 3,31; bl _s8009C07C_2; lbzx 3,3,30; extsb 3,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009C07C_0();
extern "C" void _s8009C07C_1();
extern "C" void _s8009C07C_2();
extern "C" void f_8009C07C() {}
