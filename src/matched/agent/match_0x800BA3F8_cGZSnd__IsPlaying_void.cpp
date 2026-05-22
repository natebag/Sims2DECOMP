// 0x800BA3F8 cGZSnd::IsPlaying(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); lwz 4,0x1c(3); cmpwi 4,0; beq 0f; li 0,0; lwz 11,-26564(13); stw 0,0x8(1); addi 5,1,8; lwz 9,0x0(11); lha 3,0xa8(9); lwz 0,0xac(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x18(1); b 3f; 0:; lwz 9,0x18(3); cmpwi 9,0; beq 2f; lwz 0,0xc(3); mr 3,0; cmpwi 0,0; beq 3f; lwz 0,0x14(9); li 9,0; cmpwi 0,0; beq 1f; cmpwi 7,0,-16; cror 31,30,28; mfcr 9; rlwinm 9,9,0,31,31; 1:; cmpwi 9,0; beq 3f; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void f_800BA3F8() {}
