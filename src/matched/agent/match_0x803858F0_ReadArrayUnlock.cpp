// 0x803858F0 ReadArrayUnlock (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 26,0x28(1); addi 29,3,0; lis 3,-32688; addi 0,3,-24000; mulli 8,29,272; addi 26,4,0; addi 30,5,0; addi 31,6,0; addi 27,7,0; addi 3,29,0; add 28,0,8; li 4,0; li 5,4; bl _s803858F0_0; cmpwi 3,0; bne 0f; li 3,-3; b 4f; 0:; rlwinm 26,26,0,0,19; addi 3,1,28; li 4,0; li 5,5; bl _s803858F0_1; li 0,82; cmpwi 27,0; stb 0,0x1c(1); bne 1f; rlwinm 0,26,3,30,31; stb 0,0x1d(1); rlwinm 0,26,11,24,31; rlwinm 3,26,13,30,31; stb 0,0x1e(1); rlwinm 0,26,20,25,31; stb 3,0x1f(1); stb 0,0x20(1); b 2f; 1:; rlwinm 0,26,8,24,31; stb 0,0x1d(1); rlwinm 0,26,16,24,31; stb 0,0x1e(1); 2:; addi 3,29,0; addi 4,1,28; li 5,5; li 6,1; bl _s803858F0_2; lwz 4,0x80(28); cntlzw 0,3; lwz 5,0x14(28); addi 3,29,0; rlwinm 28,0,27,5,31; addi 4,4,512; li 6,1; bl _s803858F0_3; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,29,0; addi 4,30,0; addi 5,31,0; or 28,28,0; li 6,0; bl _s803858F0_4; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 3,29,0; or 28,28,0; bl _s803858F0_5; cntlzw 0,3; rlwinm 0,0,27,5,31; or. 28,28,0; beq 3f; li 3,-3; b 4f; 3:; li 3,0; 4:; lmw 26,0x28(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s803858F0_0();
extern "C" void _s803858F0_1();
extern "C" void _s803858F0_2();
extern "C" void _s803858F0_3();
extern "C" void _s803858F0_4();
extern "C" void _s803858F0_5();
extern "C" void f_803858F0() {}
