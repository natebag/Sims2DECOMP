// 0x8038F0D8 GXSetTevIndWarp (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm. 0,6,0,24,31; stwu 1,-32(1); beq 0f; li 6,6; b 1f; 0:; li 6,0; 1:; rlwinm. 0,5,0,24,31; addi 8,6,0; beq 2f; li 6,7; b 3f; 2:; li 6,0; 3:; li 0,0; stw 0,0x8(1); addi 9,8,0; li 5,0; stw 0,0xc(1); li 10,0; bl _s8038F0D8_0; lwz 0,0x24(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038F0D8_0();
extern "C" void f_8038F0D8() {}
