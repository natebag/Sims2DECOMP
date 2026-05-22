// 0x8015A0F4 QuickDataBehaviorConstants::Release(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 9,0x1c(11); addi 3,9,-1; stw 3,0x1c(11); cmpwi 3,0; bne 1f; cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8015A0F4() {}
