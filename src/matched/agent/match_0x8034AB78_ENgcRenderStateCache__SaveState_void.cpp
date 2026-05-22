// 0x8034AB78 ENgcRenderStateCache::SaveState(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); stmw 28,0x8(1); lwz 7,-25928(13); addi 10,3,952; lwz 4,0x3b8(3); lis 11,-32688; mulli 8,7,40; lwz 0,0x4(10); lwz 6,0x8(10); addi 11,11,-12136; lwz 5,0xc(10); addi 29,3,940; addi 30,11,-12; addi 28,11,20; stwx 4,8,11; add 9,8,11; stw 0,0x4(9); add 4,8,30; stw 6,0x8(9); addi 7,7,1; stw 5,0xc(9); addi 11,11,24; lwz 0,0x10(10); stw 0,0x10(9); lwz 10,0x3ac(3); lwz 0,0x8(29); lwz 9,0x4(29); stwx 10,8,30; stw 0,0x8(4); stw 9,0x4(4); lwz 0,0x6e8(3); stwx 0,28,8; lwz 9,0x6ec(3); stw 7,-25928(13); stwx 9,11,8; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_8034AB78() {}
