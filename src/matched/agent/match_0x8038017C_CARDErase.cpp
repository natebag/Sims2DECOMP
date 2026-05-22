// 0x8038017C __CARDErase (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 6,3; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); li 31,0; stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); addi 28,3,0; mulli 5,28,272; lis 3,-32688; addi 0,3,-24000; add 30,0,5; li 0,244; stb 0,0x94(30); addi 5,4,0; li 0,-1; stb 31,0x95(30); addi 3,28,0; li 4,0; stb 31,0x96(30); stw 6,0xa0(30); stw 0,0xa4(30); stw 6,0xa8(30); bl _s8038017C_0; addi 29,3,0; cmpwi 29,-1; bne 0f; li 29,0; b 3f; 0:; cmpwi 29,0; blt 3f; lwz 5,0xa0(30); addi 3,28,0; addi 4,30,148; li 6,1; bl _s8038017C_1; cmpwi 3,0; bne 1f; stw 31,0xcc(30); li 29,-3; b 2f; 1:; li 29,0; 2:; mr 3,28; bl _s8038017C_2; mr 3,28; bl _s8038017C_3; 3:; mr 3,29; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038017C_0();
extern "C" void _s8038017C_1();
extern "C" void _s8038017C_2();
extern "C" void _s8038017C_3();
extern "C" void f_8038017C() {}
