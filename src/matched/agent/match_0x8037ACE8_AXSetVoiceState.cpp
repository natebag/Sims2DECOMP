// 0x8037ACE8 AXSetVoiceState (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s8037ACE8_0; sth 31,0x146(30); rlwinm. 0,31,0,16,31; lwz 4,0x1c(30); ori 0,4,4; stw 0,0x1c(30); bne 0f; li 0,1; stw 0,0x20(30); 0:; bl _s8037ACE8_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037ACE8_0();
extern "C" void _s8037ACE8_1();
extern "C" void f_8037ACE8() {}
