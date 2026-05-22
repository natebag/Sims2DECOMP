// 0x800AEADC cBoxX::MappedEvent(ERSoundEvent (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,4; mr 6,5; lbz 4,0x14(7); li 5,0; bl _s800AEADC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AEADC_0();
extern "C" void f_800AEADC() {}
