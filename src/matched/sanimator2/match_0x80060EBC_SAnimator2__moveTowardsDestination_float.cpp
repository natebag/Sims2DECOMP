// 0x80060EBC SAnimator2::moveTowardsDestination(float (668 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f28,0x28(1); stfd f29,0x30(1); stfd f30,0x38(1); stfd f31,0x40(1); stmw 28,0x18(1); stw 0,0x4c(1); mr 31,3; mr 29,4; lwz 0,0x108(31); mr 30,5; lfs f30,0x9c(31); cmpwi 0,2; bne 0f; lfs f30,0xa8(31); b 7f; 0:; cmpwi 0,3; bne 1f; lfs f30,0xac(31); b 7f; 1:; cmpwi 0,1; bne 2f; lfs f30,0xa0(31); b 7f; 2:; cmpwi 0,7; beq 4f; cmpwi 0,8; bne 3f; lis 9,-32707; lfs f30,0x47e0(9); b 7f; 3:; cmpwi 0,4; beq 6f; cmpwi 0,5; bne 5f; 4:; lis 9,-32707; lfs f30,0x47dc(9); b 7f; 5:; cmpwi 0,6; bne 7f; 6:; lis 9,-32707; lfs f30,0x47e4(9); 7:; lfs f0,0x4(30); lfs f12,0x20(31); lfs f11,0x1c(31); lfs f13,0x0(30); fsubs f0,f0,f12; fmuls f1,f0,f0; stfs f0,0xc(1); fsubs f13,f13,f11; fmadds f1,f13,f13,f1; stfs f13,0x8(1); bl _s80060EBC_0; lis 9,-32707; fmr f29,f1; lfs f0,0x47e8(9); fcmpu 0,f29,f0; bge 9f; lwz 4,0x668(31); cmpwi 4,0; beq 8f; lwz 3,0x8(31); lis 9,-32707; lis 11,-32707; lfs f1,0x47e4(9); lfs f3,0x47ec(11); addi 3,3,820; lfs f2,-32292(13); bl _s80060EBC_1; li 0,0; stw 0,0x668(31); 8:; lwz 0,0x61c(31); lis 9,-32707; lfs f0,0x47e4(9); rlwinm 0,0,0,29,27; stfs f0,0x110(31); stw 0,0x61c(31); b 14f; 9:; lis 9,-32707; lfs f0,0x8(1); lfs f13,0x47f0(9); addi 11,1,8; lfs f11,0xfc(31); lis 9,-32707; fdivs f13,f13,f29; lfs f12,0x47e4(9); mr 28,11; fmuls f0,f0,f13; stfs f0,0x8(1); fcmpu 0,f11,f12; lfs f0,0x4(11); fmuls f0,f0,f13; stfs f0,0x4(11); beq 10f; lfs f0,0x104(31); lis 9,-32707; lfs f13,0x47f4(9); fmuls f0,f11,f0; fdivs f31,f13,f0; b 11f; 10:; lis 9,-32707; lfs f31,0x47f8(9); 11:; lfs f4,0x0(29); mr 3,31; fmr f2,f31; fmr f3,f29; fmr f1,f30; bl _s80060EBC_2; fmr f28,f1; mr 3,31; fmr f1,f29; addi 4,31,1564; fmr f3,f31; fmr f2,f30; bl _s80060EBC_3; stfs f28,0x114(31); lfs f13,0x0(29); fmuls f1,f28,f13; fcmpu 0,f1,f29; ble 12f; lis 9,-32707; lfs f0,0x47e4(9); fcmpu 0,f1,f0; ble 12f; fsubs f0,f1,f29; fdivs f0,f0,f1; fmuls f0,f13,f0; stfs f0,0x0(29); lfs f13,0x0(30); stfs f13,0x1c(31); lfs f0,0x4(30); stfs f0,0x20(31); b 13f; 12:; lis 9,-32707; lfs f0,0x8(1); lfs f13,0x47e4(9); addi 11,31,28; lfs f12,0x4(28); fmuls f0,f0,f1; stfs f13,0x0(29); stfs f0,0x10(1); fmuls f12,f12,f1; lfs f13,0x1c(31); stfs f12,0x14(1); fadds f13,f13,f0; stfs f13,0x1c(31); lfs f0,0x4(11); fadds f0,f0,f12; stfs f0,0x4(11); 13:; fdivs f0,f28,f30; lwz 0,0x18(31); cmpwi 0,3; stfs f0,0x110(31); beq 14f; lis 9,-32707; lfs f0,0x47e4(9); stfs f0,0x110(31); 14:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x18(1); lfd f28,0x28(1); lfd f29,0x30(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"

extern "C" void _s80060EBC_0();
extern "C" void _s80060EBC_1();
extern "C" void _s80060EBC_2();
extern "C" void _s80060EBC_3();

struct SAnimator2 {
    void moveTowardsDestination();
};

void SAnimator2::moveTowardsDestination() {
}
