// 0x8024D0E0 LCFlushQueue (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); li 0,0; stw 0,0x8(1); li 4,1; li 3,0; lbz 0,0xb(1); rlwimi 0,4,0,31,31; stb 0,0xb(1); bl _s8024D0E0_0; lwz 3,0x8(1); bl _s8024D0E0_1; bl _s8024D0E0_2; lwz 0,0x14(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024D0E0_0();
extern "C" void _s8024D0E0_1();
extern "C" void _s8024D0E0_2();
extern "C" void f_8024D0E0() {}
