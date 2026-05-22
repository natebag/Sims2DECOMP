// 0x800EB758 cXObjectImpl::IsChair(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4(3); lwz 9,0x4(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,26; lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800EB758() {}
