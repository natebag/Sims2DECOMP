// 0x80132224 cXPortalImpl::PostLoad(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x0(31); bl _s80132224_0; cmpwi 30,51; bgt 0f; mr 3,31; li 4,1; bl _s80132224_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80132224_0();
extern "C" void _s80132224_1();
extern "C" void f_80132224() {}
