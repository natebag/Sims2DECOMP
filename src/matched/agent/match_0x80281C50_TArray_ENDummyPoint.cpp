// 0x80281C50 TArray<ENDummyPoint, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; beq 0f; lwz 5,0x4(31); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80281C50_0; 0:; andi. 0,30,1; beq 1f; mr 3,31; bl _s80281C50_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 3f; cmpwi 3,0; beq 2f; lis 11,-32694; li 0,0; addi 9,11,-16032; stw 0,-16032(11); addi 10,9,12; addi 8,9,36; stw 0,0x8(10); addi 11,9,24; stw 0,0x8(8); stw 0,0x8(11); stw 0,0x24(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x4(10); stw 0,0x18(9); stw 0,0x4(11); stw 0,0x4(8); b 3f; 2:; lis 3,-32694; li 4,2; addi 3,3,-16032; bl _s80281C50_2; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80281C50_0();
extern "C" void _s80281C50_1();
extern "C" void _s80281C50_2();
extern "C" void f_80281C50() {}
