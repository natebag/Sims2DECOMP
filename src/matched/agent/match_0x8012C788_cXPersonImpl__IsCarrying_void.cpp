// 0x8012C788 cXPersonImpl::IsCarrying(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x0(3); li 4,0; lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x2bc(9); lha 3,0x2b8(9); mtspr 8,0; add 3,10,3; blrl; lha 0,0x4(3); li 3,1; cmpwi 0,0; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8012C788() {}
