// 0x80048844 InfluenceMap::InfluenceMap(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mullw 30,4,5; mr 28,3; stw 4,0x0(28); stw 5,0x4(28); rlwinm 3,30,4,0,27; addi 31,30,-1; ori 3,3,8; bl _s80048844_0; addi 29,3,8; cmpwi 30,0; stw 30,-8(29); mr 30,29; beq 1f; 0:; mr 3,30; bl _s80048844_1; addi 30,30,16; cmpwi 31,0; addi 31,31,-1; bne 0b; 1:; stw 29,0x8(28); mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80048844_0();
extern "C" void _s80048844_1();
extern "C" void f_80048844() {}
