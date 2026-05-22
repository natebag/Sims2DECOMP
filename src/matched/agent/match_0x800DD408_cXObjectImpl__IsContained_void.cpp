// 0x800DD408 cXObjectImpl::IsContained(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); mr 4,3; addi 3,1,8; bl _s800DD408_0; lwz 0,0x14(1); li 3,1; cmpwi 0,0; bne 0f; li 3,0; 0:; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s800DD408_0();
extern "C" void f_800DD408() {}
