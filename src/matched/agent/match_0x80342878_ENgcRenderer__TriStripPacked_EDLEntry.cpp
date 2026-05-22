// 0x80342878 ENgcRenderer::TriStripPacked(EDLEntry (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 9,4; li 11,1; lbz 0,0x1(9); lwz 4,0x4(9); cmpwi 0,0; bne 0f; li 11,0; 0:; lwz 10,0x1c(9); lwz 5,0x8(9); lwz 6,0xc(9); lwz 7,0x10(9); lwz 8,0x14(9); lwz 9,0x18(9); stw 11,0x8(1); bl _s80342878_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80342878_0();
extern "C" void f_80342878() {}
