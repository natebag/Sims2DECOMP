// 0x801845E4 ActionQueueHUD::ActionQueueHUD(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; li 29,8; addi 31,30,156; li 27,0; li 28,0; 0:; stb 27,0x11(31); mr 3,31; stw 28,0x8(31); li 4,0; li 5,0; li 6,0; li 7,0; addi 31,31,20; bl _s801845E4_0; cmpwi 29,0; addi 29,29,-1; bne 0b; addi 31,30,344; li 29,17; li 27,0; li 28,0; 1:; stb 27,0x11(31); mr 3,31; stw 28,0x8(31); li 4,0; li 5,0; li 6,0; li 7,0; addi 31,31,20; bl _s801845E4_1; cmpwi 29,0; addi 29,29,-1; bne 1b; li 0,0; li 9,255; mr 3,30; stw 9,0x314(30); stb 0,0x319(30); stw 0,0x150(30); stw 0,0x154(30); stb 0,0x308(30); stb 0,0x309(30); stb 0,0x30a(30); stw 0,0x0(30); stw 0,0x30c(30); stw 0,0x310(30); stb 0,0x318(30); bl _s801845E4_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801845E4_0();
extern "C" void _s801845E4_1();
extern "C" void _s801845E4_2();
extern "C" void f_801845E4() {}
