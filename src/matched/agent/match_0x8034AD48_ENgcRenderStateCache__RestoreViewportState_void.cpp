// 0x8034AD48 ENgcRenderStateCache::RestoreViewportState(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stmw 30,0x8(1); lwz 11,-25924(13); lis 9,-32688; addi 9,9,-11788; addi 10,3,2480; addi 11,11,-1; addi 30,9,24; mulli 7,11,40; stw 11,-25924(13); addi 5,3,2504; lwzx 4,7,9; add 8,7,30; add 9,7,9; lwz 0,0x8(9); lwz 11,0xc(9); lwz 6,0x4(9); stw 4,0x9b0(3); stw 6,0x4(10); stw 0,0x8(10); stw 11,0xc(10); lwz 0,0x14(9); lwz 11,0x10(9); stw 0,0x14(10); stw 11,0x10(10); lwzx 0,7,30; lwz 9,0xc(8); lwz 11,0x4(8); lwz 10,0x8(8); stw 0,0x9c8(3); stw 9,0xc(5); stw 11,0x4(5); stw 10,0x8(5); lwz 0,0x6cc(3); oris 0,0,32768; ori 0,0,1536; stw 0,0x6cc(3); lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8034AD48() {}
