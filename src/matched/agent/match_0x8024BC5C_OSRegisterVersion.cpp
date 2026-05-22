// 0x8024BC5C OSRegisterVersion (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); mr 4,3; crxor 6,6,6; addi 3,13,-27924; bl _s8024BC5C_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024BC5C_0();
extern "C" void f_8024BC5C() {}
