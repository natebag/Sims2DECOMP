// 0x8038F3F4 GXSetTevIndBumpXYZ (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 7,5,0; stw 0,0x4(1); li 0,0; li 5,0; stwu 1,-32(1); li 6,7; li 8,0; stw 0,0x8(1); li 9,0; li 10,0; stw 0,0xc(1); bl _s8038F3F4_0; lwz 0,0x24(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038F3F4_0();
extern "C" void f_8038F3F4() {}
