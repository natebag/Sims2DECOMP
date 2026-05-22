// 0x800EB4B4 cXObjectImpl::IsSupport(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x4(3); lwz 9,0x4(3); lha 0,0x3f8(9); lwz 9,0x3fc(9); add 3,3,0; mtspr 8,9; blrl; xori 3,3,6; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800EB4B4() {}
