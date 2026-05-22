// 0x8037B820 AXSetVoiceLpfCoefs (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,5,0; stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; bl _s8037B820_0; sth 30,0x1f6(29); sth 31,0x1f8(29); lwz 0,0x1c(29); oris 0,0,64; stw 0,0x1c(29); bl _s8037B820_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037B820_0();
extern "C" void _s8037B820_1();
extern "C" void f_8037B820() {}
