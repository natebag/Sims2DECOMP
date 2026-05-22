// 0x8037B470 AXSetVoiceLoopAddr (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s8037B470_0; rlwinm 0,31,16,16,31; sth 0,0x1aa(30); sth 31,0x1ac(30); lwz 0,0x1c(30); ori 0,0,16384; stw 0,0x1c(30); bl _s8037B470_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037B470_0();
extern "C" void _s8037B470_1();
extern "C" void f_8037B470() {}
