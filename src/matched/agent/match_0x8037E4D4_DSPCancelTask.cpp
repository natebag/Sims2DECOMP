// 0x8037E4D4 DSPCancelTask (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8037E4D4_0; lwz 0,0x8(31); ori 0,0,2; stw 0,0x8(31); bl _s8037E4D4_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037E4D4_0();
extern "C" void _s8037E4D4_1();
extern "C" void f_8037E4D4() {}
