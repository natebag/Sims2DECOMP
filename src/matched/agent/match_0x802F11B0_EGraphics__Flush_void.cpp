// 0x802F11B0 EGraphics::Flush(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,-26824(13); bl _s802F11B0_0; cmpwi 3,0; beq 2f; lwz 11,0x324(31); cmpwi 11,0; beq 1f; lbz 0,0x18(11); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; bne 1f; lwz 9,0x70(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 3,-25912(13); lwz 9,0x338(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802F11B0_0();
extern "C" void f_802F11B0() {}
