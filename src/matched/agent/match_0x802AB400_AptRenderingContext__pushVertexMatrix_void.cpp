// 0x802AB400 AptRenderingContext::pushVertexMatrix(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,0x3bc(3); addi 10,3,32; lwz 0,0x20(3); mulli 9,8,24; lwz 11,0xc(10); lwz 7,0x4(10); addi 8,8,1; lwz 6,0x8(10); add 9,9,3; stw 0,0x238(9); addi 9,9,568; stw 7,0x4(9); stw 6,0x8(9); stw 11,0xc(9); lwz 0,0x14(10); lwz 11,0x10(10); stw 0,0x14(9); stw 11,0x10(9); stw 8,0x3bc(3)"
extern "C" void f_802AB400() {}
