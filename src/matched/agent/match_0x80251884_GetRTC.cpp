// 0x80251884 GetRTC (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,1; stw 0,0x4(1); li 5,0; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; li 3,0; bl _s80251884_0; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; li 3,0; li 4,1; li 5,3; bl _s80251884_1; cmpwi 3,0; bne 1f; li 3,0; bl _s80251884_2; li 3,0; b 2f; 1:; lis 0,8192; stw 0,0xc(1); addi 4,1,12; li 3,0; li 5,4; li 6,1; li 7,0; bl _s80251884_3; cntlzw 0,3; rlwinm 31,0,27,5,31; li 3,0; bl _s80251884_4; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; addi 4,1,12; li 3,0; li 5,4; li 6,0; li 7,0; bl _s80251884_5; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80251884_6; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80251884_7; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; li 3,0; bl _s80251884_8; lwz 4,0xc(1); cntlzw 0,31; rlwinm 3,0,27,5,31; stw 4,0x0(30); 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80251884_0();
extern "C" void _s80251884_1();
extern "C" void _s80251884_2();
extern "C" void _s80251884_3();
extern "C" void _s80251884_4();
extern "C" void _s80251884_5();
extern "C" void _s80251884_6();
extern "C" void _s80251884_7();
extern "C" void _s80251884_8();
extern "C" void f_80251884() {}
