// 0x802F19BC EGraphics::AllocVertexData(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; bl _s802F19BC_0; mr 4,30; li 5,32; li 6,0; li 7,0; bl _s802F19BC_1; mr. 3,3; bne 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F19BC_0();
extern "C" void _s802F19BC_1();
extern "C" void f_802F19BC() {}
