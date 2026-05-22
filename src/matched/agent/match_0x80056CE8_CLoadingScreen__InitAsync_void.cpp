// 0x80056CE8 CLoadingScreen::InitAsync(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); li 0,1; lis 9,-32697; stw 0,0x350(3); lwz 3,0x5ee4(9); cmpwi 3,0; beq 0f; bl _s80056CE8_0; mr. 3,3; beq 0f; bl _s80056CE8_1; mr. 6,3; beq 0f; lwz 0,0xc(6); cmpwi 0,1; bne 0f; lis 9,-32707; li 0,0; lfs f0,0x38f0(9); lis 11,-32707; stw 0,0x8(1); addi 8,1,12; stfs f0,0xc(1); lis 10,-32707; lfs f12,0x38f4(11); addi 9,1,8; stfs f0,0x8(8); addi 11,6,20; stfs f0,0x4(8); mr 3,6; lfs f13,0x38f8(10); li 4,1; stfs f12,0x10(9); stfs f13,0x18(1); lwz 0,0x8(1); lwz 10,0x4(9); lwz 8,0x8(9); lwz 7,0xc(9); stw 0,0x14(6); stw 10,0x4(11); stw 8,0x8(11); stw 7,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); bl _s80056CE8_2; 0:; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s80056CE8_0();
extern "C" void _s80056CE8_1();
extern "C" void _s80056CE8_2();
extern "C" void f_80056CE8() {}
