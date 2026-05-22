// 0x802E07F0 EBitArray::Add(EBitArray (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,6; lwz 6,0x4(3); bl _s802E07F0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E07F0_0();
extern "C" void f_802E07F0() {}
