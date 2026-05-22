// 0x800AFF60 cBoxX::PauseSFX(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x6c(3); li 4,0; lwz 11,-24136(13); addi 9,9,1; stw 9,0x6c(3); lwz 3,0x50(11); bl _s800AFF60_0; lwz 9,-24136(13); li 4,1; lwz 3,0x50(9); bl _s800AFF60_1; lwz 9,-24136(13); li 4,3; lwz 3,0x50(9); bl _s800AFF60_2; lwz 3,-24136(13); bl _s800AFF60_3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AFF60_0();
extern "C" void _s800AFF60_1();
extern "C" void _s800AFF60_2();
extern "C" void _s800AFF60_3();
extern "C" void f_800AFF60() {}
