// 0x800E2AD4 cXObjectImpl::GetCTilePt(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 5,0x68(4); mr 30,3; lwz 0,0x6c(4); lwz 6,0x80(4); srawi 5,5,4; srawi 4,0,4; bl _s800E2AD4_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800E2AD4_0();
extern "C" void f_800E2AD4() {}
