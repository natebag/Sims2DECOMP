// 0x800C71F0 cXMTObjectImpl::IsDynamic(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x0(3); li 4,8; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800C71F0() {}
