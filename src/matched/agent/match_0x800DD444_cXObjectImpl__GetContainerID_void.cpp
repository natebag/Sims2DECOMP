// 0x800DD444 cXObjectImpl::GetContainerID(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); mr 4,3; addi 3,1,8; bl _s800DD444_0; lwz 9,0x14(1); cmpwi 9,0; beq 0f; lwz 3,0x4(9); lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s800DD444_0();
extern "C" void f_800DD444() {}
