// 0x8034ACB8 ENgcRenderStateCache::SaveViewportState(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stmw 30,0x8(1); lwz 5,-25924(13); addi 10,3,2480; lwz 8,0x9b0(3); lis 9,-32688; mulli 6,5,40; lwz 0,0x4(10); lwz 11,0x8(10); addi 9,9,-11788; lwz 4,0xc(10); addi 30,9,24; addi 7,3,2504; addi 5,5,1; stwx 8,6,9; add 9,6,9; add 8,6,30; stw 0,0x4(9); stw 11,0x8(9); stw 4,0xc(9); lwz 0,0x14(10); lwz 11,0x10(10); stw 0,0x14(9); stw 11,0x10(9); lwz 0,0x9c8(3); lwz 9,0xc(7); lwz 11,0x4(7); lwz 10,0x8(7); stwx 0,6,30; stw 9,0xc(8); stw 11,0x4(8); stw 10,0x8(8); stw 5,-25924(13); lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8034ACB8() {}
