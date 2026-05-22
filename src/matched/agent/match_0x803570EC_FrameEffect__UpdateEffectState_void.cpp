// 0x803570EC FrameEffect::UpdateEffectState(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0xc(31); cmpwi 0,2; bne 0f; lwz 9,0x10(31); lfs f1,0x8(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 0,4; lwz 9,0x10(31); stw 0,0xc(31); li 4,4; lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 0,0xc(31); cmpwi 0,8; bne 1f; lwz 9,0x10(31); lfs f1,0x8(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 0,1; lwz 9,0x10(31); stw 0,0xc(31); li 4,1; lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_803570EC() {}
