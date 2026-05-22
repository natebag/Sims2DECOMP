// 0x80252664 __OSReadROM (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s80252664_0; li 3,0; li 4,1; li 5,0; bl _s80252664_1; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; li 3,0; li 4,1; li 5,3; bl _s80252664_2; cmpwi 3,0; bne 1f; li 3,0; bl _s80252664_3; li 3,0; b 2f; 1:; rlwinm 0,31,6,0,25; stw 0,0x14(1); addi 4,1,20; li 3,0; li 5,4; li 6,1; li 7,0; bl _s80252664_4; cntlzw 0,3; rlwinm 31,0,27,5,31; li 3,0; bl _s80252664_5; cntlzw 0,3; rlwinm 0,0,27,5,31; addi 4,29,0; addi 5,30,0; or 31,31,0; li 3,0; li 6,0; li 7,0; bl _s80252664_6; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80252664_7; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80252664_8; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80252664_9; cntlzw 0,31; rlwinm 3,0,27,5,31; 2:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80252664_0();
extern "C" void _s80252664_1();
extern "C" void _s80252664_2();
extern "C" void _s80252664_3();
extern "C" void _s80252664_4();
extern "C" void _s80252664_5();
extern "C" void _s80252664_6();
extern "C" void _s80252664_7();
extern "C" void _s80252664_8();
extern "C" void _s80252664_9();
extern "C" void f_80252664() {}
