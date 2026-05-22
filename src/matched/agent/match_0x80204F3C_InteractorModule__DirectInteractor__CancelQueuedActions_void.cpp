// 0x80204F3C InteractorModule::DirectInteractor::CancelQueuedActions(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x70(31); cmpwi 11,0; beq 1f; lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 0,0x10(3); cmpwi 0,1; bne 0f; lwz 3,0x70(31); lwz 9,0x4(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; lwz 3,0x70(31); lwz 9,0x4(3); lha 0,0xd0(9); lwz 9,0xd4(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80204F3C() {}
