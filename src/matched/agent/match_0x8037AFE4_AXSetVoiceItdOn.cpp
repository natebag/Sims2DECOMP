// 0x8037AFE4 AXSetVoiceItdOn (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8037AFE4_0; li 0,1; sth 0,0x16e(31); li 0,0; sth 0,0x17a(31); sth 0,0x178(31); sth 0,0x176(31); sth 0,0x174(31); lwz 0,0x1c(31); rlwinm 0,0,0,26,24; stw 0,0x1c(31); lwz 0,0x1c(31); ori 0,0,32; stw 0,0x1c(31); bl _s8037AFE4_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037AFE4_0();
extern "C" void _s8037AFE4_1();
extern "C" void f_8037AFE4() {}
