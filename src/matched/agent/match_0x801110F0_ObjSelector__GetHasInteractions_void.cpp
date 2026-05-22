// 0x801110F0 ObjSelector::GetHasInteractions(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s801110F0_0; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(11); lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,1; bne 1f; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801110F0_0();
extern "C" void f_801110F0() {}
