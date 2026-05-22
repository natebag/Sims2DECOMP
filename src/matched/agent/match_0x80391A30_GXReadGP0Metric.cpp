// 0x80391A30 GXReadGP0Metric (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); addi 3,1,12; addi 4,1,8; bl _s80391A30_0; lwz 3,0xc(1); lwz 0,0x14(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80391A30_0();
extern "C" void f_80391A30() {}
