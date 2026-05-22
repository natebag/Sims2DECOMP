// 0x8034439C ENgcRenderer::WindowMatrix(EDLEntry (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26052(13); cmpwi 0,0; beq 0f; li 0,0; stw 0,-26052(13); 0:; lwz 8,0x4(4); addi 7,3,1176; lwz 9,0x0(8); lwz 10,0x4(8); stw 9,0x498(3); stw 10,0x49c(3); lwz 11,0x8(8); lwz 12,0xc(8); stw 11,0x8(7); stw 12,0xc(7); lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x10(7); stw 10,0x14(7); lwz 11,0x18(8); lwz 12,0x1c(8); stw 11,0x18(7); stw 12,0x1c(7); lwz 9,0x20(8); lwz 10,0x24(8); stw 9,0x20(7); stw 10,0x24(7); lwz 11,0x28(8); lwz 12,0x2c(8); stw 11,0x28(7); stw 12,0x2c(7); lwz 9,0x30(8); lwz 10,0x34(8); stw 9,0x30(7); stw 10,0x34(7); lwz 11,0x38(8); lwz 12,0x3c(8); stw 11,0x38(7); stw 12,0x3c(7)"
extern "C" void f_8034439C() {}
