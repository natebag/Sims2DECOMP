// 0x8039DDC8 void (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,6; li 6,0; bl _s8039DDC8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8039DDC8_0();
extern "C" void f_8039DDC8() {}
