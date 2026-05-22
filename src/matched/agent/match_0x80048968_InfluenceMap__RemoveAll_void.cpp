// 0x80048968 InfluenceMap::RemoveAll(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 29,0; lwz 0,0x0(30); cmpw 29,0; bge 3f; 0:; lwz 0,0x4(30); li 31,0; addi 28,29,1; cmpw 31,0; bge 2f; 1:; mullw 3,29,0; lwz 0,0x8(30); add 3,3,31; rlwinm 3,3,4,0,27; addi 31,31,1; add 3,0,3; bl _s80048968_0; lwz 0,0x4(30); cmpw 31,0; blt 1b; 2:; lwz 0,0x0(30); mr 29,28; cmpw 29,0; blt 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80048968_0();
extern "C" void f_80048968() {}
