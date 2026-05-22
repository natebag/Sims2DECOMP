// 0x80252974 OSSetSoundMode (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,-24704; stw 30,0x18(1); rlwinm 30,3,2,29,29; bl _s80252974_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s80252974_1; li 31,0; b 1f; 0:; stw 3,0x44(31); li 0,1; stw 0,0x0(4); 1:; lbz 3,0x13(31); rlwinm 0,3,0,29,29; cmplw 30,0; bne 2f; li 3,0; li 4,0; bl _s80252974_2; b 3f; 2:; rlwinm 0,3,0,30,28; stb 0,0x13(31); li 3,1; li 4,0; lbz 0,0x13(31); or 0,0,30; stb 0,0x13(31); bl _s80252974_3; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80252974_0();
extern "C" void _s80252974_1();
extern "C" void _s80252974_2();
extern "C" void _s80252974_3();
extern "C" void f_80252974() {}
