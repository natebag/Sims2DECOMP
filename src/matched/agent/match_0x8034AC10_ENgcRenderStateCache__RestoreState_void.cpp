// 0x8034AC10 ENgcRenderStateCache::RestoreState(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); stmw 28,0x8(1); lwz 11,-25928(13); lis 9,-32688; addi 9,9,-12136; addi 10,3,952; addi 11,11,-1; addi 4,9,-12; mulli 8,11,40; addi 29,9,20; addi 28,9,24; stw 11,-25928(13); addi 30,3,940; lwzx 6,8,9; add 5,8,4; add 9,8,9; lwz 0,0x8(9); lwz 11,0xc(9); lwz 7,0x4(9); stw 6,0x3b8(3); stw 7,0x4(10); stw 0,0x8(10); stw 11,0xc(10); lwz 0,0x10(9); stw 0,0x10(10); lwzx 9,8,4; lwz 0,0x8(5); lwz 11,0x4(5); stw 9,0x3ac(3); stw 0,0x8(30); stw 11,0x4(30); lwzx 9,29,8; lwz 0,0x6cc(3); stw 9,0x6e8(3); oris 0,0,32768; lwzx 9,28,8; ori 0,0,64; stw 0,0x6cc(3); stw 9,0x6ec(3); lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_8034AC10() {}
