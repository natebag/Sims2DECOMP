// 0x80364F64 ETexture::ETexture(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32697; lis 10,-28659; mr 9,3; li 0,0; li 6,64; addi 11,11,-9440; li 8,1; li 7,32; ori 10,10,48879; stw 11,0x24(9); sth 6,0x10(9); stb 8,0x18(9); stb 7,0x1a(9); stw 0,0x1c(9); stw 10,0x20(9); stw 0,0x0(9); stw 0,0x4(9); stw 0,0x8(9); sth 6,0x12(9); stb 0,0x19(9); stb 0,0x1b(9); sth 0,0x14(9); sth 0,0x16(9)"
extern "C" void f_80364F64() {}
