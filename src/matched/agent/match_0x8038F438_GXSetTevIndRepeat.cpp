// 0x8038F438 GXSetTevIndRepeat (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,0; stw 0,0x4(1); li 0,0; li 5,0; stwu 1,-24(1); li 6,0; li 7,0; stw 0,0x8(1); li 8,6; li 9,6; stw 0,0xc(1); li 10,1; bl _s8038F438_0; lwz 0,0x1c(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038F438_0();
extern "C" void f_8038F438() {}
