// 0x80329824 ImageProcessingManager::FilterParams::Reset(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 0,0; lfs f0,0x1274(9); li 9,0; stb 0,0xb(3); sth 9,0x4(3); stfs f0,0x18(3); stb 0,0x2(3); stb 0,0x0(3); stb 0,0x1(3); stb 0,0x8(3); stb 0,0x9(3); stb 0,0xa(3); stfs f0,0xc(3); stfs f0,0x10(3); stfs f0,0x14(3)"
extern "C" void f_80329824() {}
