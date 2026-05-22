// 0x800BB0D8 cGZMusic::SetPan(int) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-24468(13); stw 4,0x18(3); lwz 31,0x40c(9); cmpw 31,3; bne 0f; lwz 0,0x410(9); cmpwi 0,0; bne 0f; lwz 0,0x20(31); cmpwi 0,0; bne 0f; lwz 29,-26564(13); mr 3,31; lwz 30,0x0(29); lha 0,0x60(30); addi 30,30,96; add 29,29,0; bl _s800BB0D8_0; lwz 0,0x4(30); mr 3,29; mtspr 8,0; blrl; lwz 29,-26564(13); mr 3,31; lwz 30,0x0(29); lha 0,0x70(30); addi 30,30,112; add 29,29,0; bl _s800BB0D8_1; lwz 0,0x4(30); mr 3,29; mtspr 8,0; blrl; 0:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800BB0D8_0();
extern "C" void _s800BB0D8_1();
extern "C" void f_800BB0D8() {}
