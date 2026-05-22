// 0x8037B518 AXSetVoiceCurrentAddr (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s8037B518_0; rlwinm 0,31,16,16,31; sth 0,0x1b2(30); sth 31,0x1b4(30); lwz 0,0x1c(30); oris 0,0,1; stw 0,0x1c(30); bl _s8037B518_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037B518_0();
extern "C" void _s8037B518_1();
extern "C" void f_8037B518() {}
