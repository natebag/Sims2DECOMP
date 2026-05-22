// 0x80251E4C WriteSram (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 6,-32731; stw 0,0x4(1); addi 0,6,7660; stwu 1,-40(1); stw 31,0x24(1); addi 31,4,0; li 4,1; stw 30,0x20(1); addi 30,5,0; mr 5,0; stw 29,0x1c(1); addi 29,3,0; li 3,0; bl _s80251E4C_0; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; li 3,0; li 4,1; li 5,3; bl _s80251E4C_1; cmpwi 3,0; bne 1f; li 3,0; bl _s80251E4C_2; li 3,0; b 2f; 1:; rlwinm 31,31,6,0,25; addi 0,31,256; oris 0,0,40960; stw 0,0x14(1); addi 4,1,20; li 3,0; li 5,4; li 6,1; li 7,0; bl _s80251E4C_3; cntlzw 0,3; rlwinm 31,0,27,5,31; li 3,0; bl _s80251E4C_4; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 4,29,0; addi 5,30,0; or 31,31,0; li 3,0; li 6,1; bl _s80251E4C_5; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80251E4C_6; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80251E4C_7; cntlzw 0,31; rlwinm 3,0,27,5,31; 2:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80251E4C_0();
extern "C" void _s80251E4C_1();
extern "C" void _s80251E4C_2();
extern "C" void _s80251E4C_3();
extern "C" void _s80251E4C_4();
extern "C" void _s80251E4C_5();
extern "C" void _s80251E4C_6();
extern "C" void _s80251E4C_7();
extern "C" void f_80251E4C() {}
