// 0x800C7D88 cXMTObjectImpl::CAST_IMPL(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 3,3; bne 0f; li 3,0; b 1f; 0:; lwz 3,0x4(3); lwz 9,0x4(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800C7D88() {}
