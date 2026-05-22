// 0x8025A338 SIGetTypeAsync (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); addi 28,3,0; bl _s8025A338_0; addi 30,3,0; addi 3,28,0; bl _s8025A338_1; lis 4,-32700; rlwinm 5,28,2,0,29; addi 0,4,-15952; add 4,0,5; lwz 0,0x0(4); addi 29,3,0; rlwinm. 0,0,0,24,24; beq 3f; lis 3,-32694; rlwinm 4,28,4,0,27; addi 0,3,-21520; add 4,0,4; lwz 0,0x0(4); li 5,0; cmplw 0,31; beq 4f; cmplwi 0,0; bne 0f; rlwinm 0,5,2,0,29; stwx 31,4,0; b 4f; 0:; addi 3,4,4; lwz 0,0x4(4); li 5,1; cmplw 0,31; beq 4f; cmplwi 0,0; bne 1f; rlwinm 0,5,2,0,29; stwx 31,4,0; b 4f; 1:; lwzu 0,0x4(3); li 5,2; cmplw 0,31; beq 4f; cmplwi 0,0; bne 2f; rlwinm 0,5,2,0,29; stwx 31,4,0; b 4f; 2:; lwz 0,0x4(3); li 5,3; cmplw 0,31; beq 4f; cmplwi 0,0; bne 4f; rlwinm 0,5,2,0,29; stwx 31,4,0; b 4f; b 4f; 3:; addi 12,31,0; mtspr 8,12; addi 3,28,0; addi 4,29,0; blrl; 4:; mr 3,30; bl _s8025A338_2; mr 3,29; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025A338_0();
extern "C" void _s8025A338_1();
extern "C" void _s8025A338_2();
extern "C" void f_8025A338() {}
