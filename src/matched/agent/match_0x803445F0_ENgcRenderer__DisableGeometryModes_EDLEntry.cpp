// 0x803445F0 ENgcRenderer::DisableGeometryModes(EDLEntry (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4d8(3); lwz 10,0x4(4); lwz 0,0x6cc(9); oris 0,0,32768; stw 0,0x6cc(9); lwz 11,0x4d8(3); lwz 0,0x6e8(11); and 0,0,10; stw 0,0x6e8(11); lwz 9,0x4d8(3); lwz 0,0x6e8(9); andi. 11,0,4; beq 0f; li 0,2; b 1f; 0:; andi. 0,0,2; beq 1f; li 0,1; 1:; stw 0,0x79c(9); li 0,1; stw 0,0x510(3)"
extern "C" void f_803445F0() {}
