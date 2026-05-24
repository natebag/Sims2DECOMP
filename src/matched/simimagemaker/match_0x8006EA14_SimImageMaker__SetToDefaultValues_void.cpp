// 0x8006EA14 SimImageMaker::SetToDefaultValues(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 22,0x8(1); stw 0,0x3c(1); mr 30,3; li 4,0; li 25,0; bl _s8006EA14_0; addi 31,30,276; mr 3,30; li 4,0; bl _s8006EA14_1; li 9,32; li 0,8; stw 25,0xc(30); li 4,0; stw 9,0x4(30); li 5,104; stw 0,0x8(30); addi 3,30,144; stw 9,0x0(30); bl _s8006EA14_2; lis 0,-820; lis 9,-32696; ori 0,0,37054; addi 11,9,22036; stw 0,0x218(30); addi 7,30,496; lis 6,-32696; addi 4,30,508; lwz 0,0x5614(9); addi 5,6,22048; lwz 10,0x8(11); lis 9,-32707; lwz 8,0x4(11); lis 3,-32694; stw 0,0x1f0(30); lis 11,-32707; stw 10,0x8(7); addi 27,3,7432; stw 8,0x4(7); addi 29,30,520; lfs f0,0x5298(9); lis 28,-32696; lwz 0,0x5620(6); lis 9,-32696; lwz 10,0x8(5); addi 24,9,22120; lwz 8,0x4(5); lis 9,-32696; stw 0,0x1fc(30); addi 23,9,22072; stw 10,0x8(4); addi 7,28,22060; stw 8,0x4(4); addi 26,30,248; lfs f31,0x529c(11); li 6,3; lwz 11,0x1d08(3); addi 22,24,24; lwz 0,0x8(27); lwz 9,0x4(27); stw 11,0x208(30); stw 0,0x8(29); stw 9,0x4(29); stfs f0,0x214(30); lwz 0,0x562c(28); lwz 9,0x8(7); lwz 11,0x4(7); stw 0,0xf8(30); stw 9,0x8(26); stw 11,0x4(26); stw 6,0x1e8(30); stw 25,0x1ec(30); 0:; lwz 0,0x0(23); lwz 9,0x4(23); lwz 11,0x8(23); stw 0,-12(31); stw 9,-8(31); stw 11,-4(31); lwz 0,0x0(24); lwz 9,0x4(24); lwz 11,0x8(24); stw 0,0x0(31); stw 9,0x4(31); lfs f0,0x0(31); stw 11,0x8(31); fcmpu 0,f0,f31; bne 1f; lfs f0,0x4(31); fcmpu 0,f0,f31; bne 1f; lfs f0,0x8(31); fcmpu 0,f0,f31; beq 2f; 1:; mr 3,31; mr 4,31; bl _s8006EA14_3; 2:; addi 24,24,12; addi 31,31,24; addi 23,23,12; cmpw 24,22; ble 0b; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x8(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s8006EA14_0();
extern "C" void _s8006EA14_1();
extern "C" void _s8006EA14_2();
extern "C" void _s8006EA14_3();

struct SimImageMaker {
    void SetToDefaultValues();
};

void SimImageMaker::SetToDefaultValues() {
}
