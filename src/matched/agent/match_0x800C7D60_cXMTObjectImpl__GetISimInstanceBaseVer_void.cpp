// 0x800C7D60 cXMTObjectImpl::GetISimInstanceBaseVer(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lwz 3,0x0(9); bl _s800C7D60_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800C7D60_0();
extern "C" void f_800C7D60() {}
