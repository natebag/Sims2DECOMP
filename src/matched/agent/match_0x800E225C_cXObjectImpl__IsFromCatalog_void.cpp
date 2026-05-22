// 0x800E225C cXObjectImpl::IsFromCatalog(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4(3); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x4e(3); cmpwi 0,0; bne 0f; lha 0,0x50(3); cmpwi 0,0; beq 1f; 0:; li 3,1; b 2f; 1:; lha 0,0x8a(3); li 3,1; cmpwi 0,0; bne 2f; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800E225C() {}
