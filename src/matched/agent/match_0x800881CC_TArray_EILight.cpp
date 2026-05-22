// 0x800881CC TArray<EILight (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 5,4; li 4,3; bl _s800881CC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x18(3)"
extern "C" void _s800881CC_0();
extern "C" void f_800881CC() {}
