// 0x80100C84 cXObjectImpl::TryPreloadObject(StackElem (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lhz 0,0x4(5); lwz 31,-21508(13); andi. 9,0,1; beq 0f; lwz 9,0x0(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; li 3,0; li 4,1; b 2f; 0:; lwz 4,0x0(5); cmpwi 4,0; beq 1f; lwz 9,0x0(31); lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 9,0x0(31); mr 4,3; li 5,0; lha 3,0x160(9); lwz 0,0x164(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,0; li 4,1; bne 2f; li 3,0; li 4,2; b 2f; 1:; li 3,0; li 4,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80100C84() {}
