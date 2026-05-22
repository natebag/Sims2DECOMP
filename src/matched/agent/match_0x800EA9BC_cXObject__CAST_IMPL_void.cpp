// 0x800EA9BC cXObject::CAST_IMPL(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800EA9BC() {}
