// 0x803820A0 CARDCheckAsync (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 5,4,0; stw 0,0x4(1); stwu 1,-24(1); addi 4,1,16; bl _s803820A0_0; lwz 0,0x1c(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803820A0_0();
extern "C" void f_803820A0() {}
