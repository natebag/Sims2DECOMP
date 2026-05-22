// 0x800DD49C cXObjectImpl::GetContainedSlotNum(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); mr 4,3; addi 3,1,8; bl _s800DD49C_0; lha 3,0x1a(1); lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s800DD49C_0();
extern "C" void f_800DD49C() {}
