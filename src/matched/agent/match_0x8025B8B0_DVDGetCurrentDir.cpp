// 0x8025B8B0 DVDGetCurrentDir (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; addi 5,30,0; stw 29,0x14(1); addi 29,3,0; addi 4,29,0; lwz 31,-23496(13); addi 3,31,0; bl _s8025B8B0_0; cmplw 3,30; bne 0f; li 0,0; add 3,29,30; stb 0,-1(3); b 5f; 0:; mulli 0,31,12; lwz 4,-23508(13); lwzx 0,4,0; rlwinm. 0,0,0,0,7; bne 1f; li 0,0; b 2f; 1:; li 0,1; 2:; cmpwi 0,0; beq 4f; addi 0,30,-1; cmplw 3,0; bne 3f; li 0,0; stbx 0,29,3; b 5f; 3:; li 0,47; stbx 0,29,3; addi 3,3,1; 4:; li 0,0; stbx 0,29,3; li 0,1; 5:; mr 3,0; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025B8B0_0();
extern "C" void f_8025B8B0() {}
