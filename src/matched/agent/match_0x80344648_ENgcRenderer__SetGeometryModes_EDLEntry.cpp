// 0x80344648 ENgcRenderer::SetGeometryModes(EDLEntry (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4d8(3); lwz 10,0x4(4); lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); lwz 9,0x4d8(3); stw 10,0x6e8(9); lwz 9,0x4d8(3); lwz 0,0x6e8(9); andi. 11,0,4; beq 0f; li 0,2; b 1f; 0:; andi. 0,0,2; beq 1f; li 0,1; 1:; stw 0,0x79c(9); li 0,1; stw 0,0x510(3)"
extern "C" void f_80344648() {}
