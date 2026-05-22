// 0x8037B0A4 AXSetVoiceUpdateIncrement (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8037B0A4_0; lwz 4,0x24(31); addi 0,4,1; stw 0,0x24(31); lwz 0,0x1c(31); ori 0,0,128; stw 0,0x1c(31); bl _s8037B0A4_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037B0A4_0();
extern "C" void _s8037B0A4_1();
extern "C" void f_8037B0A4() {}
