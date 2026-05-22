// 0x801486CC TreeSimImpl::GetCurElem(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 30,3,12; mr 3,30; bl _s801486CC_0; addi 4,3,-1; mr 3,30; bl _s801486CC_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801486CC_0();
extern "C" void _s801486CC_1();
extern "C" void f_801486CC() {}
