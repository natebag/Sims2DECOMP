// 0x802E0774 EBitArray::Insert(EBitArray (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 6,5; lwz 7,0x4(4); li 5,0; bl _s802E0774_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E0774_0();
extern "C" void f_802E0774() {}
