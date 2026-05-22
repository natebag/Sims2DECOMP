// 0x8006E814 SimImageMaker::SimImageMaker(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; li 0,32; li 9,8; stw 30,0xc(31); addi 3,31,16; stw 0,0x4(31); stw 0,0x0(31); stw 9,0x8(31); bl _s8006E814_0; li 0,4; stw 30,0x8c(31); mtspr 9,0; stw 30,0x88(31); 0:; bdnz 0b; li 0,4; addi 4,31,496; mtspr 9,0; addi 30,31,508; addi 12,31,520; 1:; bdnz 1b; lis 9,-32696; lis 10,-32696; lfs f0,0x5614(9); addi 8,10,22048; addi 9,9,22036; lis 7,-32694; stfs f0,0x1f0(31); addi 6,7,7432; lis 11,-32707; lis 0,-820; lfs f0,0x4(9); ori 0,0,37054; lfs f12,0x5294(11); li 5,0; stfs f0,0x4(4); mr 3,31; lfs f0,0x8(9); stfs f0,0x8(4); lfs f13,0x5620(10); stfs f13,0x1fc(31); lfs f0,0x4(8); stfs f0,0x4(30); lfs f13,0x8(8); stfs f13,0x8(30); lfs f0,0x1d08(7); stfs f0,0x208(31); lfs f13,0x4(6); stfs f13,0x4(12); lfs f0,0x8(6); stfs f0,0x8(12); stfs f12,0x214(31); stw 0,0x218(31); stw 5,0x21c(31); bl _s8006E814_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006E814_0();
extern "C" void _s8006E814_1();
extern "C" void f_8006E814() {}
