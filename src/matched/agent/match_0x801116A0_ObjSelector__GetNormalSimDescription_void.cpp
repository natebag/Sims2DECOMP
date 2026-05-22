// 0x801116A0 ObjSelector::GetNormalSimDescription(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x98(3); cmpwi 11,0; bne 0f; lwz 3,0x8c(3); b 1f; 0:; lwz 9,0x4(11); lha 3,0x158(9); lwz 0,0x15c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801116A0() {}
