// 0x8023F2F0 CasCostumes::UpdateSimDescription(bool, (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="andi. 28,31,511; beq 10f; b 3f; 0:; bl _s8023F2F0_0; 1:; bl _s8023F2F0_1; cmpwi 3,0; beq 1b; 2:; bl _s8023F2F0_2; bl _s8023F2F0_3; cmpwi 3,255; beq 2b; bl _s8023F2F0_4; lis 29,-13312; stw 30,0x682c(29); li 5,512; stw 5,0x6830(29); li 3,7; stw 3,0x6834(29); bl _s8023F2F0_5; add 30,30,5; addi 28,28,-1; cmpwi 28,0; bne 0b; andi. 28,31,511; beq 10f; 3:; bl _s8023F2F0_6; 4:; bl _s8023F2F0_7; cmpwi 3,0; beq 4b; 5:; bl _s8023F2F0_8; bl _s8023F2F0_9; cmpwi 3,255; beq 5b; bl _s8023F2F0_10; andi. 29,31,480; beq 6f; lis 28,-13312; stw 30,0x682c(28); stw 29,0x6830(28); li 3,7; stw 3,0x6834(28); add 30,30,29; andi. 29,29,31; bl _s8023F2F0_11; 6:; andi. 28,31,28; beq 8f; li 29,0; 7:; lwzx 3,30,29; bl _s8023F2F0_12; addi 29,29,4; cmpw 29,28; blt 7b; add 30,30,29; 8:; andi. 28,31,3; beq 10f; li 29,0; 9:; lbzx 3,30,29; bl _s8023F2F0_13; addi 29,29,1; cmpw 29,28; blt 9b; 10:; li 3,15; mtspr 9,3; 11:; bdnz 11b; bl _s8023F2F0_14; li 3,0; lwz 31,0x8(1); lwz 30,0xc(1); lwz 29,0x10(1); lwz 28,0x14(1); lwz 0,0x1c(1); addi 1,1,24; mtspr 8,0; blr; blr; blr; mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); li 0,4096; lis 5,-13312; stw 0,0x3000(5); lis 5,-32701; ori 5,5,42048; lwz 5,0x0(5); cmpwi 5,0; beq 12f; mtspr 8,5; lis 5,-32701; ori 5,5,42056; li 0,1; stb 0,0x0(5); blrl; 12:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0; blr; lis 4,-13312; lwz 3,0x6828(4); andi. 3,3,5; ori 3,3,208; stw 3,0x6828(4); blr; lis 4,-13312; lwz 3,0x6828(4); andi. 3,3,5; stw 3,0x6828(4); blr; lis 4,-13312; lwz 5,0x6828(4); andi. 5,5,5; stw 5,0x6828(4); li 3,6; mtspr 9,3; 13:; bdnz 13b; ori 5,5,208; stw 5,0x6828(4); blr; lis 4,-13312; 14:; lwz 3,0x6834(4); rlwinm. 3,3,0,31,31; bne 14b; blr; mfspr 4,8; stw 4,0x4(1); stwu 1,-8(1); lis 4,-13312; li 3,0; stw 3,0x6838(4); li 3,1; stw 3,0x6834(4); bl _s8023F2F0_15; lis 4,-13312; lwz 3,0x6838(4); rlwinm 3,3,8,24,31; lwz 4,0xc(1); addi 1,1,8; mtspr 8,4"
extern "C" void _s8023F2F0_0();
extern "C" void _s8023F2F0_1();
extern "C" void _s8023F2F0_2();
extern "C" void _s8023F2F0_3();
extern "C" void _s8023F2F0_4();
extern "C" void _s8023F2F0_5();
extern "C" void _s8023F2F0_6();
extern "C" void _s8023F2F0_7();
extern "C" void _s8023F2F0_8();
extern "C" void _s8023F2F0_9();
extern "C" void _s8023F2F0_10();
extern "C" void _s8023F2F0_11();
extern "C" void _s8023F2F0_12();
extern "C" void _s8023F2F0_13();
extern "C" void _s8023F2F0_14();
extern "C" void _s8023F2F0_15();
extern "C" void f_8023F2F0() {}
