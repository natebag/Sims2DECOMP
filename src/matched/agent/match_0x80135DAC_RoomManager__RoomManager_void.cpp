// 0x80135DAC RoomManager::RoomManager(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 30,3; li 29,0; stw 29,0x4(30); li 3,24; addi 28,30,16; bl _s80135DAC_0; mr 9,3; stw 29,0x8(30); stw 9,0x4(30); li 3,36; stb 29,0xc(30); stw 29,0x0(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); stw 29,0x4(28); bl _s80135DAC_1; mr 9,3; stw 29,0x8(28); stw 9,0x4(28); lis 10,-32706; stb 29,0xc(28); mr 3,30; stw 29,0x0(9); lfs f0,-11496(10); lwz 11,0x4(28); stw 29,0x4(11); lwz 9,0x4(28); stw 9,0x8(9); lwz 11,0x4(28); stw 11,0xc(11); stw 29,0x24(30); stfs f0,0x2c(30); stw 29,0x20(30); stfs f0,0x28(30); stw 30,-31676(13); lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s80135DAC_0();
extern "C" void _s80135DAC_1();
extern "C" void f_80135DAC() {}
